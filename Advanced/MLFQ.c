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

int main(){
    
    int len1;
    scanf("%d", &len1);

    Process processes[len1];

    Output result[len1];
    int len2 = 0;

    for(int x = 0; x < len1; x++){
        scanf("%d", &processes[x].pid);
        scanf("%d", &processes[x].at);
        scanf("%d", &processes[x].bt);
        processes[x].rt = processes[x].bt;
    }

    for(int x = 0; x < len1 - 1; x++){
        for(int y = 0; y < len1 - x - 1; y++){
            if(processes[y].at > processes[y + 1].at){
                Process temp = processes[y];
                processes[y] = processes[y + 1];
                processes[y + 1] = temp;
            }
        }
    }

    int time = 0;

    for(int x = 0; x < len1; x++){

        printf("%d | %d\n", processes[x].pid, time);

        if(processes[x].rt > 2){
            time += 2;
            processes[x].rt -= 2;
        }
        else{
            time += processes[x].rt;
            processes[x].rt = 0;

            result[len2].pid = processes[x].pid;
            result[len2].ct = time;
            result[len2].tat =  result[len2].ct - processes[x].at;
            result[len2].wt =  result[len2].tat - processes[x].bt;

            len2++;
        }

    }

    for(int x = 0; x < len1; x++){
        if(processes[x].rt > 0){
            printf("%d | %d\n", processes[x].pid, time);

            if(processes[x].rt > 3){
                time += 3;
                processes[x].rt -= 3;
            }
            else{
                time += processes[x].rt;
                processes[x].rt = 0;

                result[len2].pid = processes[x].pid;
                result[len2].ct = time;
                result[len2].tat =  result[len2].ct - processes[x].at;
                result[len2].wt =  result[len2].tat - processes[x].bt;

                len2++;
            }
        }
    }

    for(int x = 0; x < len1 - 1; x++){
        for(int y = 0; y < len1 - x - 1; y++){
            if(processes[y].rt > processes[y + 1].rt){
                Process temp = processes[y];
                processes[y] = processes[y + 1];
                processes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < len1; x++){
        if(processes[x].rt > 0){
            if(time < processes[x].at) time = processes[x].at;

            printf("%d | %d\n", processes[x].pid, time);

            time += processes[x].bt;

            result[len2].pid = processes[x].pid;
            result[len2].ct = time;
            result[len2].tat =  result[len2].ct - processes[x].at;
            result[len2].wt =  result[len2].tat - processes[x].bt;

            len2++;
        }
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