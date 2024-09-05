#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <omp.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int V;
    int **capacity, **flow;
    int *height, *excess;
    omp_lock_t *node_locks;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (!g) {
        fprintf(stderr, "Memory allocation failed for Graph\n");
        exit(1);
    }
    g->V = V;
    g->capacity = (int**)malloc(V * sizeof(int*));
    g->flow = (int**)malloc(V * sizeof(int*));
    g->height = (int*)calloc(V, sizeof(int));
    g->excess = (int*)calloc(V, sizeof(int));
    g->node_locks = (omp_lock_t*)malloc(V * sizeof(omp_lock_t));

    if (!g->capacity || !g->flow || !g->height || !g->excess || !g->node_locks) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < V; ++i) {
        g->capacity[i] = (int*)calloc(V, sizeof(int));
        g->flow[i] = (int*)calloc(V, sizeof(int));
        if (!g->capacity[i] || !g->flow[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        omp_init_lock(&g->node_locks[i]);
    }

    return g;
}

void addEdge(Graph* g, int u, int v, int cap) {
    g->capacity[u][v] = cap;
}

void push(Graph* g, int u, int v) {
    if (u < v) {
        omp_set_lock(&g->node_locks[u]);
        omp_set_lock(&g->node_locks[v]);
    } else {
        omp_set_lock(&g->node_locks[v]);
        omp_set_lock(&g->node_locks[u]);
    }

    int flow = MIN(g->excess[u], g->capacity[u][v] - g->flow[u][v]);
    g->flow[u][v] += flow;
    g->flow[v][u] -= flow;
    g->excess[u] -= flow;
    g->excess[v] += flow;

    if (u < v) {
        omp_unset_lock(&g->node_locks[v]);
        omp_unset_lock(&g->node_locks[u]);
    } else {
        omp_unset_lock(&g->node_locks[u]);
        omp_unset_lock(&g->node_locks[v]);
    }
}

void relabel(Graph* g, int u) {
    omp_set_lock(&g->node_locks[u]);

    int min_height = INT_MAX;
    for (int v = 0; v < g->V; v++) {
        if (g->capacity[u][v] - g->flow[u][v] > 0) {
            omp_set_lock(&g->node_locks[v]);
            min_height = MIN(min_height, g->height[v]);
            omp_unset_lock(&g->node_locks[v]);
        }
    }
    if (min_height < INT_MAX) {
        g->height[u] = min_height + 1;
    }

    omp_unset_lock(&g->node_locks[u]);
}

void initPreflow(Graph* g, int source) {
    g->height[source] = g->V;
    for (int v = 0; v < g->V; v++) {
        int flow = g->capacity[source][v];
        g->flow[source][v] = flow;
        g->flow[v][source] = -flow;
        g->excess[v] = flow;
        g->excess[source] -= flow;
    }
}

int pushRelabelMaxFlow(Graph* g, int source, int sink) {
    initPreflow(g, source);

    int *active = (int*)calloc(g->V, sizeof(int));
    for (int i = 0; i < g->V; i++) {
        if (i != source && i != sink) active[i] = 1;
    }

    while (1) {
        int work_done = 0;

        #pragma omp parallel for schedule(dynamic) reduction(|:work_done)
        for (int u = 0; u < g->V; u++) {
            if (active[u]) {
                active[u] = 0;
                while (g->excess[u] > 0) {
                    for (int v = 0; v < g->V; v++) {
                        if (g->excess[u] > 0 && g->height[u] == g->height[v] + 1 && g->capacity[u][v] - g->flow[u][v] > 0) {
                            push(g, u, v);
                            if (v != source && v != sink) {
                                #pragma omp atomic write
                                active[v] = 1;
                            }
                            work_done = 1;
                        }
                    }
                    if (g->excess[u] > 0) {
                        relabel(g, u);
                        active[u] = 1;
                        work_done = 1;
                        break;
                    }
                }
            }
        }

        if (!work_done) break;
    }

    free(active);
    return g->excess[sink];
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        free(g->capacity[i]);
        free(g->flow[i]);
        omp_destroy_lock(&g->node_locks[i]);
    }
    free(g->capacity);
    free(g->flow);
    free(g->height);
    free(g->excess);
    free(g->node_locks);
    free(g);
}

int main() {
    int V = 6;  // Number of vertices
    Graph* g = createGraph(V);

    // Add edges (u, v, capacity)
    addEdge(g, 0, 1, 16);
    addEdge(g, 0, 2, 13);
    addEdge(g, 1, 2, 10);
    addEdge(g, 1, 3, 12);
    addEdge(g, 2, 1, 4);
    addEdge(g, 2, 4, 14);
    addEdge(g, 3, 2, 9);
    addEdge(g, 3, 5, 20);
    addEdge(g, 4, 3, 7);
    addEdge(g, 4, 5, 4);

    int source = 0, sink = 5;

    #pragma omp parallel
    {
        #pragma omp single
        printf("Number of threads: %d\n", omp_get_num_threads());
    }

    int maxFlow = pushRelabelMaxFlow(g, source, sink);
    printf("Maximum Flow: %d\n", maxFlow);

    freeGraph(g);
    return 0;
}