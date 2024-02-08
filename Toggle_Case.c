#include <stdio.h>

int main(){

    char Str[50];

    printf("Enter the String to Toggle the Case : ");
    scanf("%s", &Str[0]);

    printf("\n");

    char* ptr = &Str[0];

    printf("The String After Toggling the Case is : ");

    while(*ptr!='\0'){

        if(*ptr>=97 && *ptr<=122){

            *ptr-=32;

        }

        else if(*ptr>=65 && *ptr<=90){

            *ptr+=32;

        }

        printf("%c", *ptr);

        ptr++;

    }

    printf("\n");

    return 0;

}