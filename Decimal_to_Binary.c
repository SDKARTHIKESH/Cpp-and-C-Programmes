#include <stdio.h>
#include <math.h>

void Binary(int Num);

int main(){

    int Number;
    scanf("%d", &Number);

    Binary(Number);

    return 0;

}

void Binary(int Num){

    int Max_Power = pow(2, log2(Num));

    while(Num!=0 || Max_Power!=0){

        printf("%d", Num/Max_Power);

        if(Num/Max_Power==1){

            Num-=Max_Power;

        }

        Max_Power/=2;

    }

}