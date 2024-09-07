#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int rt;
} Process;

typedef struct {
    int pid;
    int ct;
    int tat;
    int wt;
    int rt;
} Output;

void SRTF(Process processes[], int len1, Output result[], int *len2);

int main() {

    int len1;
    scanf("%d", &len1);

    Process processes[len1];

    for(int x = 0; x < len1; x++){
        scanf("%d", &processes[x].pid);
        scanf("%d", &processes[x].at);
        scanf("%d", &processes[x].bt);
        processes[x].rt = processes[x].bt;
    }

    Output result[len1];
    int len2 = 0;

    SRTF(processes, len1, result, &len2);

    for(int x = 0; x < len2 - 1; x++){
        for(int y = 0; y < len2 - x - 1; y++){
            if(result[y].pid > result[y + 1].pid){
                Output temp = result[y];
                result[y] = result[y + 1];
                result[y + 1] = temp;
            }
        }
    }

    printf("PID | CT | TAT | WT | RT\n");
    for(int x = 0; x < len2; x++) 
        printf("P%d | %d | %d | %d | %d\n", result[x].pid, result[x].ct, result[x].tat, result[x].wt, result[x].rt);

    return 0;

}

void SRTF(Process processes[], int len1, Output result[], int *len2){

    int time;

    if(*len2 == 0) time = processes[0].at;
    else time = result[*len2 - 1].ct;
    
    int completed = 0, min = 10000, shortest = 0;
    int isCompleted[len1], rt[len1], started[len1], responseTime[len1];

    for(int x = 0; x < len1; x++){
        isCompleted[x] = 0;
        rt[x] = processes[x].rt;
        started[x] = 0;
    }

    printf("Process | Time\n");

    while(completed != len1){

        for(int x = 0; x < len1; x++){
            if (processes[x].at <= time && isCompleted[x] == 0 && rt[x] < min){
                min = rt[x];
                shortest = x;
            }
        }

        if(min == 10000){
            time++;
            continue;
        }

        if(started[shortest] == 0){
            responseTime[shortest] = time;
            started[shortest] = 1;
        }

        rt[shortest]--;
        min = rt[shortest];

        printf("P%d | %d\n", processes[shortest].pid, time);        

        if (rt[shortest] == 0) {

            time++;
            
            result[*len2].pid = processes[shortest].pid;
            result[*len2].ct = time;
            result[*len2].tat = time - processes[shortest].at;
            result[*len2].wt = result[*len2].tat - processes[shortest].bt;
            result[*len2].rt = responseTime[shortest];

            isCompleted[shortest] = 1;
            completed++;
            (*len2)++;

            min = 10000;

            continue;

        }

        time++;

    }

    printf("\n");

}