#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int q;
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

void roundRobin(Process processes[], int len1, int qt, Output result[], int *len2);
void fcfs(Process processes[], int len1, Output result[], int *len2);

int main(){

    int len1;
    scanf("%d", &len1);

    Process processes[len1];

    for(int x = 0; x < len1; x++){
        scanf("%d", &processes[x].pid);
        scanf("%d", &processes[x].at);
        scanf("%d", &processes[x].bt);
        scanf("%d", &processes[x].q);
        processes[x].rt = processes[x].bt;
    }

    Output result[len1];
    int len2 = 0;

    int counter = 1;

	while(counter <= 4){

		Process processing[len1];
		int innerCount = 0;

		for(int y = 0;  y < len1; y++){

			if(processes[y].q == counter){
				processing[innerCount] = processes[y];
				innerCount++;
			}

		}

		if(counter == 1) roundRobin(processing, innerCount, 2, result, &len2);
		else if(counter == 2) roundRobin(processing, innerCount, 3, result, &len2);
		else if(counter == 3) roundRobin(processing, innerCount, 4, result, &len2);
		else fcfs(processing, innerCount, result, &len2);

		counter++;

	}

    for(int x = 0; x < len2 - 1; x++){
        for(int y = 0; y < len2 - x - 1; y++){
            if(result[y].pid > result[y + 1].pid){
                Output temp = result[y];
                result[y] = result[y + 1];
                result[y + 1] = temp;
            }
        }
    }

    printf("\nPID | CT | TAT | WT\n");
    for(int x = 0; x < len2; x++) 
        printf("P%d | %d | %d | %d\n", result[x].pid, result[x].ct, result[x].tat, result[x].wt);

    return 0;

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


void roundRobin(Process processes[], int len1, int qt, Output result[], int *len2){

    for(int x = 0; x < len1 - 1; x++){
        for(int y = 0; y < len1 - x - 1; y++){
            if(processes[y].at > processes[y + 1].at){
                Process temp = processes[y];
                processes[y] = processes[y + 1];
                processes[y + 1] = temp;
            }
        }
    }

    int time;

    if(*len2 == 0) time = processes[0].at;
    else time = result[*len2 - 1].ct;

    Queue *readyQueue = createQueue();

    int index = 0;

    while(1){

        while(processes[index].at <= time && index < len1){
            push(readyQueue, processes[index]);
            index++;
        }

        if(isEmpty(readyQueue) == 0){

            Process element = pop(readyQueue);
            printf("%d | %d\n", element.pid, time);

            if(qt < element.rt){

                element.rt -= qt;
                time += qt;

                while(processes[index].at <= time && index < len1){
                    push(readyQueue, processes[index]);
                    index++;
                }

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
        else if(index < len1) time++;
        else break;

    }

}

void fcfs(Process processes[], int len1, Output result[], int *len2){

    for(int x = 0; x < len1 - 1; x++){
        for(int y = 0; y < len1 - x - 1; y++){
            if(processes[y].at > processes[y + 1].at){
                Process temp = processes[y];
                processes[y] = processes[y + 1];
                processes[y + 1] = temp;
            }
        }
    }

    int time;

    if(*len2 == 0) time = processes[0].at;
    else time = result[*len2 - 1].ct;

    for(int x = 0; x < len1; x++){

        if(time < processes[x].at) time = processes[x].at;

        printf("%d | %d\n", processes[x].pid, time);

        time += processes[x].bt;

        result[*len2].pid = processes[x].pid;
        result[*len2].ct = time;
        result[*len2].tat =  result[*len2].ct - processes[x].at;
        result[*len2].wt =  result[*len2].tat - processes[x].bt;

        (*len2)++;

    }

}