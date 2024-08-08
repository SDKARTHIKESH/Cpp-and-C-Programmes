#include <stdio.h>
#include <pthread.h>
#include <math.h>

int length(int Number);
int isArmstrong(int Number);
int isPrime(int Number);

void *printPrime();
void *printArmstrong();

int main(){

	pthread_t a, b;

    pthread_create(&a, NULL, printPrime, NULL);
    pthread_create(&b, NULL, printArmstrong, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

	return 0;

}

int length(int Number){

    int Counter = 0;

    while (Number != 0) {

        Number /= 10;
        Counter++;

    }

    return Counter;

}

int isArmstrong(int Number){

    int Sum = 0, Var = Number;
    int Len = length(Var);

    while (Var != 0) {

        Sum += pow(Var % 10, Len);
        Var /= 10;

    }

    if (Number == Sum) return 1;

    return 0;

}

int isPrime(int Num){

    if (Num == 1) return 0;
    if (Num == 2) return 1;

    if (Num % 2 != 0) {

        int Var = sqrt(Num) + 1;

        for (int y = 3; y < Var; y += 2) {

            if (Num % y == 0) return 0;

        }

    }

    else return 0;

    return 1;

}

void *printPrime(){

    for(int x = 1; x <= 1000; x++){

        if(isPrime(x)) printf("Prime Number: %d\n", x);

    }

    return NULL;

}

void *printArmstrong(){

    for(int x = 1; x <= 1000; x++){

        if(isArmstrong(x)) printf("Armstrong: %d\n", x);

    }

    return NULL;

}