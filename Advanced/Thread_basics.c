#include <stdio.h>
#include <pthread.h>

void *odd(void *ptr);
void *even(void *ptr);

int main(){

	pthread_t a, b;

    pthread_create(&a, NULL, odd, NULL);
    pthread_create(&b, NULL, even, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

	return 0;

}

void *odd(void *ptr){

	for(int x = 1; x <= 1000; x+=2){
	
		printf("Odd: %d\n", x);

	}

    return NULL;

}

void *even(void *ptr){

	for(int x = 0; x <= 1000; x+=2){

		printf("Even: %d\n", x);

	}

    return NULL;

}