#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int flag[2];
int turn;
int number = 0;

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

void *increment(void *s){

    int x = 0;
    int a;
    int other = *((int *)s);

    lock(other);

    number++;
    printf("Now the Number is: %d\n", number);

    unlock(other);

}

void *decrement(void *s){

    int x = 0;
    int a;
    int other = *((int *)s);

    lock(other);

    number--;
    printf("Now the Number is: %d\n", number);

    unlock(other);

}

int main(){

    pthread_t t1, t2;
    number = 1283;

    int thread_ids[2] = {0, 1};

    printf("Before Operation: %d\n", number);

    lock_init();

    pthread_create(&t1, NULL, increment, &thread_ids[0]);
    pthread_create(&t2, NULL, decrement, &thread_ids[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Result: %d\n", number);

    return 0;

}
