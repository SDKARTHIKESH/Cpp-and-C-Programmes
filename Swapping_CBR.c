#include <stdio.h>

void Swap(int* Num1, int* Num2);

int main(){

    int Number1, Number2;

    printf("Enter the First Number : ");
    scanf("%d", &Number1);

    printf("Enter the Second Number : ");
    scanf("%d", &Number2);

    printf("\n");

    printf("The Numbers before Swapping are : %d and %d", Number1, Number2);
    printf("\n\n");

    Swap(&Number1, &Number2);

    printf("The Numbers after Swapping are : %d and %d", Number1, Number2);
    printf("\n\n");

    return 0;

}

void Swap(int* Num1, int* Num2){

    int Temp = *Num1;

    *Num1=*Num2;
    *Num2=Temp;

    return;

}