#include <stdio.h>
#include <math.h>

void Binary(int Num);

int main(){

    int Number;

    printf("Enter the Number to Convert to Binary : ");
    scanf("%d", &Number);

    printf("\n");

    Binary(Number);

    return 0;

}

void Binary(int Num){

    int Var=log2(Num);
    int Max_Power = pow(2, Var);

    while(Num!=0 || Max_Power!=0){

        printf("%d", Num/Max_Power);

        if(Num/Max_Power==1){

            Num-=Max_Power;

        }

        Max_Power/=2;

    }

    printf("\n");

    return;

}