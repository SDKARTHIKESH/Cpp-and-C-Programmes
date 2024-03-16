#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    char Ch, Str1[100], Str2[100];
    
    scanf("%c", &Ch);
    scanf("%s", &Str1[0]);
    scanf("%[^\n]%*c", &Str2[0]);
    
    printf("%c\n", Ch);
    printf("%s\n", Str1);
    printf("%s\n", Str2);
    
    return 0;
}