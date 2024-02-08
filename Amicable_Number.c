#include <stdio.h>
#include <math.h>

int Sum_of_Factors(int Num);

int main(){

    int Number1, Number2;

    printf("Enter the First Number : ");
    scanf("%d", &Number1);

    printf("Enter the Second Number : ");
    scanf("%d", &Number2);

    printf("\n");

    if(Sum_of_Factors(Number1)==Number2 && Sum_of_Factors(Number2)==Number1){

        printf("%d and %d are Amicable Numbers\n", Number1, Number2);

    }

    else{

        printf("%d and %d are not Amicable Numbers\n", Number1, Number2);

    }

    return 0;

}

int Sum_of_Factors(int Num){

    int Var = sqrt(Num);
    int Sum=1;

    for(int x=2; x<Var+1; x++){

        if(Num%x==0){

            Sum+=x;
            Sum+=(Num/x);

        }

    }

    return Sum;

}