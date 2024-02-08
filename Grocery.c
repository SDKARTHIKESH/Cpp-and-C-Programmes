#include <stdio.h>

int Sum(int* Prices, int* Quantity, int Len);
int Discount(int Total);
void Print(int* Prices, int* Quantity, int Len);

int main(){

    int Number;

    printf("Enter the Number of Items : ");
    scanf("%d", &Number);

    printf("\n");

    int Prices[Number], Quantity[Number];

    printf("Enter the Price and the Quantity for each Item : \n\n");

    for(int x=0; x<Number; x++){

        scanf("%d", &Prices[x]);
        scanf("%d", &Quantity[x]);

    }

    printf("\n\n");

    Print(&Prices[0], &Quantity[0], Number);

    return 0; 

}

int Sum(int* Prices, int* Quantity, int Len){

    int Total=0;

    for(int x=0; x<Len; x++){

        Total+=(Prices[x]*Quantity[x]);

    }

    return Total;

}

int Discount(int Total){

    if (Total<1000){

        return Total*0.05;

    }

    else if(Total>1000 && Total<5000){

        return Total*0.1;

    }

    else{

        return Total*0.15;

    }

}

void Print(int* Prices, int* Quantity, int Len){

    int Total=Sum(Prices, Quantity, Len);
    int Disc=Discount(Total);

    printf("The Prices of Individual Items are : \n\n");

    for(int x=0; x<Len; x++){

        printf("Rs.%d\n", Prices[x]*Quantity[x]);

    }

    printf("\n");

    printf("The Total Bill Amount is Rs.%d\n", Total);
    printf("The Discount Amount is Rs.%d\n\n", Disc);

    printf("The Grand Total is Rs.%d\n", Total-Disc);

}