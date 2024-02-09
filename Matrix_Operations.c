#include <stdio.h>

void Sum(int* Mat1, int* Mat2, int* Res, int Len);
void Difference(int* Mat1, int* Mat2, int* Res, int Len);
void Product(int* Mat1, int* Mat2, int* Res, int Len);

void Print(int* Mat, int Len);
void Scan(int* Mat, int Len);
void Set0(int* Mat, int Len);

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
    
    int Result1[Len][Len], Result2[Len][Len], Result3[Len][Len];

    Set0(&Result3[0][0], Len);

    Sum(&Mat1[0][0], &Mat2[0][0], &Result1[0][0], Len);
    Difference(&Mat1[0][0], &Mat2[0][0], &Result2[0][0], Len);
    Product(&Mat1[0][0], &Mat2[0][0], &Result3[0][0], Len);
    
    printf("The Sum of the Matrices are : \n\n");
    Print(&Result1[0][0], Len);

    printf("The Difference of the Matrices are : \n\n");
    Print(&Result2[0][0], Len);

    printf("The Product of the Matrices are : \n\n");
    Print(&Result3[0][0], Len);

    return 0;

}

void Sum(int* Mat1, int* Mat2, int* Res, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            *((Res+x*Len)+y) = *((Mat1+x*Len)+y) + *((Mat2+x*Len)+y);

        }

    }

    return;

}

void Difference(int* Mat1, int* Mat2, int* Res, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            *((Res+x*Len)+y) = *((Mat1+x*Len)+y) - *((Mat2+x*Len)+y);

        }

    }

    return;

}

void Product(int* Mat1, int* Mat2, int* Res, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            for(int z=0; z<Len; z++){

                *((Res+x*Len)+y) += *((Mat1+x*Len)+z) * *((Mat2+z*Len)+y);


            }
            
        }

    }

    return;

}

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

            scanf("%d", ((Mat+x*Len)+y));

        }

        printf("\n");

    }

}

void Set0(int* Mat, int Len){

    for(int x=0; x<Len; x++){

        for(int y=0; y<Len; y++){

            *((Mat+x*Len)+y) = 0;

        }

    }

    return;

}