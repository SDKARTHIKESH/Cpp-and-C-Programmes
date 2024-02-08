#include <stdio.h>

void Bubble_Sort(int* Numbers, int Len);

int main(){

    int Len;

    printf("Enter the Number of Elements : ");
    scanf("%d", &Len);

    int Numbers[Len];

    printf("\n");

    printf("Enter the Elements of the Array : \n\n");

    for(int x=0; x<Len; x++){

        scanf("%d", &Numbers[x]);

    }

    printf("\n\n");

    Bubble_Sort(&Numbers[0], Len);

    printf("The Elements of the Array after sorting are : \n\n");

    for(int x=0; x<Len; x++){

        printf("%d\n", Numbers[x]);

    }

    return 0;

}

void Bubble_Sort(int* Numbers, int Len){

    for(int x=0; x<Len-1; x++){

        int Swapped = 0;

        for(int y=0; y<Len-x-1; y++){

            if(Numbers[y]>Numbers[y+1]){

                int Temp = Numbers[y];
                Numbers[y]=Numbers[y+1];
                Numbers[y+1]=Temp;

                Swapped=1;

            }

        }

        if (Swapped==0){

            break;

        }

    }

    return;

}