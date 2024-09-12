#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int flag[2];
int turn;
int balance = 0;

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

void *credit(void *s){

    int x = 0;
    int a;
    int other = *((int *)s);

    lock(other);

    balance += 1000;
    printf("Now the balance is: %d\n", balance);

    unlock(other);

}

void *debit(void *s){

    int x = 0;
    int a;
    int other = *((int *)s);

    lock(other);

    balance -= 200;
    printf("Now the balance is: %d\n", balance);

    unlock(other);

}

int main(){

    pthread_t t1, t2;
    balance = 1000;

    int thread_ids[2] = {0, 1};

    printf("Balance before operation: %d\n", balance);

    lock_init();

    pthread_create(&t1, NULL, credit, &thread_ids[0]);
    pthread_create(&t2, NULL, debit, &thread_ids[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Balance: %d\n", balance);

    return 0;

}