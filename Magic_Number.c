#include <stdio.h>

int Magic(int Num);

int main(){

    int Number;

    printf("Enter the Number : ");
    scanf("%d", &Number);

    printf("\n");

    if(Magic(Number)==Number){

        printf("%d is a Magic Number\n", Number);

    }

    else{

        printf("%d is not a Magic Number\n", Number);

    }

    return 0;

}

int Magic(int Num){

    int Sum=0;

    while(Num!=0){

        Sum+=(Num%10);
        Num/=10;

    }

    int Rev_Sum=0;
    int Var=Sum;

    while(Var!=0){

        Rev_Sum=(Rev_Sum*10)+(Var%10);
        Var/=10;

    }

    return Sum*Rev_Sum;

}