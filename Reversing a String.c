#include <stdio.h>

int Locate_Null(char* Begin);

int main() {
   
    char Str[20];
    char New_Str[20];
   
    printf("Enter a String (without any spaces) : ");
    scanf("%s", &Str[0]);

    int Null_Location=Locate_Null(&Str[0]);
   
    char* ptr1 = &Str[0]+Null_Location-1;
    char* ptr2 = &New_Str[0];
   
    while(*ptr1!='\0'){
       
        *ptr2=*ptr1;
       
        ptr1--;
        ptr2++;
       
    }

    *ptr2 = '\0';

    printf("\n");
    printf("The Reversed string is : %s", New_Str);
   
    printf("\n\n");

    return 0;
   
}

int Locate_Null(char* Begin){

    int Index = 0;

    while(*(Begin+Index)!='\0'){

        Index++;

    };

    return Index;

}