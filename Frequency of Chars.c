#include <stdio.h>

int main(){

    char Str[50];
    int Freq[3] = {0, 0, -1};

    printf("Enter the String : ");
    fgets(&Str[0], 50, stdin);

    printf("\n");

    char* ptr = &Str[0];

    while(*ptr!='\0'){

        if (65<=*ptr && *ptr<=90 || 97<=*ptr && *ptr<=122){

            Freq[0]++;

        }

        else if (48<=*ptr && *ptr<=57){

            Freq[1]++;

        }

        else{

            Freq[2]++;

        }

        ptr++;

    }

    printf("The Number of Alphabets in the Entered String is : %d\n", Freq[0]);
    printf("The Number of Digits in the Entered String is : %d\n", Freq[1]);
    printf("The Number of Special Characters in the Entered String is : %d\n\n", Freq[2]);

    return 0;

}