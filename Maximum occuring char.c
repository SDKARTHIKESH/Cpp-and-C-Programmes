#include <stdio.h>
#include <string.h>

int main(){

    char Str[50];

    printf("Enter the String : ");
    fgets(&Str[0], 50, stdin);

    printf("\n");

    char* ptr1 = &Str[0];

    char Characters[50];
    int Occurences[50] = {0};

    char* ptr2 = &Characters[0];
    int* ptr3 = &Occurences[0];

    char* Begin1 = &Characters[0];
    int* Begin2 = &Occurences[0];

    while(*ptr1!='\0'){

        char* Location = strchr(Characters, *ptr1);

        if(Location==NULL){

            *ptr2 = *ptr1;
            *ptr3 = 1;

            ptr2++;
            ptr3++;

        }

        else{

            *(Begin2 + (Location - Begin1))+=1;

        }

        ptr1++;

    }

    ptr2=Begin1;
    ptr3=Begin2;

    int Max = 0;
    char Max_Char;

    while(*ptr2!='\0'){

        if (*ptr3>Max){

            Max=*ptr3;
            Max_Char=*ptr2;

        }

        ptr2++;
        ptr3++;

    }

    printf("The Maximum repeated Character in the Entered String is %c with %d occurences", Max_Char, Max);
    printf("\n\n");

    return 0;

}