#include <stdio.h>
#include <unistd.h>
#include <math.h>

int length(int Number);
int isArmstrong(int Number);
int isPrime(int Number);

int main(){

	pid_t a, b;

	a = fork();

	if(a > 0){

		b = fork();

		if(b == 0){
			
			for(int x = 1; x <= 1000; x++){

                if(isArmstrong(x)) printf("Armstrong Number: %d\n", x);

            }

		}
		
	}


	else if(a == 0){

		for(int x = 1; x <= 1000; x++){

            if(isPrime(x)) printf("Prime Number: %d\n", x);

        }

	}

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
