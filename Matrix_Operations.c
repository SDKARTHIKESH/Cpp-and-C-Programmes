#include <stdio.h>

int* Sum(int* Mat1, int* Mat2, int Len);
int* Difference(int* Mat1, int* Mat2, int Len);
int* Product(int* Mat1, int* Mat2, int Len);

void Print(int* Mat, int Len);
void Scan(int* Mat, int Len);

int main(){

    int Len;

    printf("Enter the Dimension of the Square Matrix : ");
    scanf("%d", &Len);

    int Mat1[Len][Len], Mat2[Len][Len];

    printf("\n");

    printf("Enter the Matrix 1 : \n\n");
    Scan(&Mat1[0][0], Len);

    printf("Enter the Matrix 2 : \n\n");
    Scan(&Mat2[0][0], Len);
    
    int* Result1 = Sum(Mat1, Mat2, Len);
    int* Result2 = Difference(Mat1, Mat2, Len);
    int* Result3 = Product(Mat1, Mat2, Len);
    

    printf("The Sum of the Matrices are : \n\n");

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

void Scan(int* Mat, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            scanf("%d ", *((Mat+x*Len)+y));

        }

        printf("\n");

    }

}