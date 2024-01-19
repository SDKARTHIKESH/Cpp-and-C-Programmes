#include <stdio.h>

int main() {
   
    char Str[20];
   
    printf("Enter a String (without any spaces) : ");
    scanf("%s", &Str);
   
    char* ptr = &Str;
    int Counter=0;
   
    while(*ptr!='\0'){
       
        Counter++;
        ptr++;
       
    }
   
    printf("\n");
    printf("The Length of the String %s is : %d", Str, Counter);
   
    printf("\n\n");

    return 0;
   
}