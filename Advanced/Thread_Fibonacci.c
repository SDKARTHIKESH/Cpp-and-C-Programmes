#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *fibonacci(void *args);
void *argsParse(int argc, char *argv[]);

int main(int argc, char *argv[]){

    pthread_t fib;

    pthread_create(&fib, NULL, fibonacci, argsParse(argc, argv));
    pthread_join(fib, NULL);

    return 0;

}

void *argsParse(int argc, char *argv[]){

    int *args = (int *)malloc(3 * sizeof(int));

    for(int x = 1; x < argc; x++) *(args + x - 1) = atoi(argv[x]);

    return (void *)args;

}

void *fibonacci(void *args){

    int *argsArray = (int *)args;

    int num1 = *(argsArray + 0);
    int num2 = *(argsArray + 1);
    int terms = *(argsArray + 2);

    printf("Fibonacci Series of %d terms with the starting numbers %d and %d are:\n\n", terms, num1, num2);

    for(int x = 0; x < terms; x++){

        printf("%d\n", num1);

        int temp = num1 + num2;
        num1 = num2;
        num2 = temp;

    }

    return NULL;

}