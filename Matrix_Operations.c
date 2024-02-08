#include <stdio.h>

int* Sum(int* Mat1, int* Mat2, int Len);
int* Difference(int* Mat1, int* Mat2, int Len);
int* Product(int* Mat1, int* Mat2, int Len);

void Print(int* Mat, int Len);

int main(){

    int Len;

    printf("Enter the Dimension of the Square Matrix : ");
    scanf("%d", &Len);

    int Mat1[Len][Len], Mat2[Len][Len];

    return 0;

}

int* Sum(int* Mat1, int* Mat2, int Len);
int* Difference(int* Mat1, int* Mat2, int Len);
int* Product(int* Mat1, int* Mat2, int Len);

void Print(int* Mat, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            printf("%d ", *((Mat+x*Len)+y));

        }

        printf("\n");

    }

    printf("\n");

    return;

}