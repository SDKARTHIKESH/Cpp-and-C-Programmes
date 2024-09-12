#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int flag[2];
int turn;

void lock_init(){
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int other){

    flag[other] = 1;
    turn = 1 - other;
    while(flag[1 - other] == 1 && turn == 1 - other);

}

void unlock(int other){
    flag[other] = 0;
}

void *printA(void *s){

    int other = *((int *)s);

    lock(other);

    for(int x = 0; x < 10000; x++)
        printf("A ");

    unlock(other);

}

void *printNum(void *s){

    int other = *((int *)s);

    lock(other);

    for(int x = 1; x <= 100000; x++)
        printf("%d ", x);

    unlock(other);

}

int main(){

    pthread_t t1, t2;

    int thread_ids[2] = {0, 1};

    lock_init();

    pthread_create(&t1, NULL, printA, &thread_ids[0]);
    pthread_create(&t2, NULL, printNum, &thread_ids[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;

}
