#include <stdio.h>

int Modulo1(int Num1, int Num2);
int Modulo2(int Num1, int Num2);

int main(){

    int Number1, Number2;

    printf("Enter the Dividend : ");
    scanf("%d", &Number1);

    printf("Enter the Divisor : ");
    scanf("%d", &Number2);

    printf("\n");

    printf("%d is the Remainder when %d is Divided by %d\n", Modulo1(Number1, Number2), Number1, Number2);

    return 0;

}

int Modulo1(int Num1, int Num2){

    int Sum=0;

    while(Num1>=Num2){

        Num1-=Num2;

    }

    return Num1;

}

int Modulo2(int Num1, int Num2){

    int Var=Num1/Num2;

    return Num1-(Var*Num2);

}