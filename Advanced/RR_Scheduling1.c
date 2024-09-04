#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int rt;
} Process;

typedef struct{
    int pid;
    int ct;
    int tat;
    int wt;
} Output;

typedef struct{
    Process *arr;
    int len;
} Queue;

Queue *createQueue();
int isEmpty(Queue *q);
void push(Queue *q, Process element);
Process pop(Queue *q);
void printQueue(Queue *q);

void roundRobin(Process processes[], int len1, int qt, Output result[], int *len2);

int main(){

    int len1;
    scanf("%d", &len1);

    Process processes[len1];

    for(int x = 0; x < len1; x++){
        scanf("%d", &processes[x].pid);
        scanf("%d", &processes[x].at);
        scanf("%d", &processes[x].bt);
        processes[x].rt = processes[x].bt;
    }

    int qt;
    scanf("%d", &qt);

    Output result[len1];
    int len2 = 0;

    roundRobin(processes, len1, qt, result, &len2);

    printf("\nPID | CT | TAT | WT\n");
    for(int x = 0; x < len2; x++) {
        printf("P%d | %d | %d | %d\n", result[x].pid, result[x].ct, result[x].tat, result[x].wt);
}

}

Queue *createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = NULL;
    q->len = 0;
    return q;
}

int isEmpty(Queue *q){
    return q->len == 0;
}

void push(Queue *q, Process element){
    q->arr = (Process *)realloc(q->arr, ++q->len * sizeof(Process));
    *(q->arr + q->len - 1) = element;
}

Process pop(Queue *q){
    Process element = *q->arr;

    for(int x = 1; x < q->len; x++)
        *(q->arr + x - 1) = *(q->arr + x);

    --q->len;

    if(isEmpty(q) == 0) q->arr = (Process *)realloc(q->arr, q->len * sizeof(Process));
    else q->arr = NULL;

    return element;
}

void printQueue(Queue *q){
    for(int x = 0; x < q->len; x++)
        printf("%d ", (q->arr + x)->pid);
}

void roundRobin(Process processes[], int len1, int qt, Output result[], int *len2){

    int time;

    if(*len2 == 0) time = 0;
    else time = result[*len2 - 1].ct;

    Queue *readyQueue = createQueue();

    for(int x = 0; x < len1; x++)
        push(readyQueue, processes[x]);

    printf("Ready Queue | Process | Time\n");

    while(isEmpty(readyQueue) == 0){

        printQueue(readyQueue);

        Process element = pop(readyQueue);
        printf("| %d | %d\n", element.pid, time);

        if(qt < element.rt){

            element.rt -= qt;
            time += qt;

            push(readyQueue, element);

        } else{

            time += element.rt;
            element.rt = 0;

            result[*len2].pid = element.pid;
            result[*len2].ct = time;
            result[*len2].tat =  result[*len2].ct - element.at;
            result[*len2].wt =  result[*len2].tat - element.bt;

            (*len2)++;

        }

    }

}