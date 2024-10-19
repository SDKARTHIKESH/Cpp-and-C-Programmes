#include <stdio.h>
#include <stdlib.h>

int compare(int arr1[], int arr2[], int n);
void add(int arr1[], int arr2[], int n);
void print(int arr[], int n);

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int allocation[n][m], max[n][m], available[m], finish[n], need[n][m], result[n];

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            scanf("%d", &allocation[x][y]);
        }
        for(int y = 0; y < m; y++) {
            scanf("%d", &max[x][y]);
            need[x][y] = max[x][y] - allocation[x][y];
        }
        finish[x] = 0;
    }
    for(int x = 0; x < m; x++) {
        scanf("%d", &available[x]);
    }

    int is_breaked = 0;

    for(int x = 0; x < n; x++) {
        int index = -1;
        for(int y = 0; y < n; y++) {
            if(!finish[y] && compare(need[y], available, m)) {
                index = y;
                break;
            }
        }
        if(index >= 0) {
            add(available, allocation[index], m);
            finish[index] = 1;
            result[x] = index;
        } else {
            is_breaked = 1;
            break;
        }
    }

    if(is_breaked) {
        printf("The Given Processes will lead to a Deadlock\n");
    } else {
        printf("The Safe Sequence of the Processes are:\n");
        for(int x = 0; x < n; x++) {
            printf("P%d ", result[x]);
        }
        printf("\n");
    }
}

int compare(int arr1[], int arr2[], int m) {
    for(int x = 0; x < m; x++) {
        if(arr1[x] > arr2[x]) {
            return 0;
        }
    }
    return 1;
}

void add(int arr1[], int arr2[], int m) {
    for(int x = 0; x < m; x++) {
        arr1[x] += arr2[x];
    }
}