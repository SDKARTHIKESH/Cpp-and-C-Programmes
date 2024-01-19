#include <stdio.h>

int Length(char* Begin);
int Palin(char* Begin);

int main(){

    char Str[20];

    printf("Enter the String to check whether it's Palindrome or not : ");
    scanf("%s", &Str[0]);

    printf("\n");

    if (Palin(&Str[0])==1){

        printf("The Entered String is a Palindrome");

    }

    else{

        printf("The Entered String is not a Palindrome");

    }

    printf("\n");

    return 0;

}

int Length(char* Begin){

    int Index=0;

    while(*(Begin+Index)!='\0'){

        Index++;

    }

    return Index;

}

int Palin(char* Begin){

    int Len = Length(Begin)-1;
    int HalfWay = Len/2;

    for (int x = 0; x <= HalfWay; x++){

        if(*(Begin+x)!=*(Begin+Len-x)){

            return 0;

        }

    }

    return 1;

}