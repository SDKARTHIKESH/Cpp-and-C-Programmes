#include <stdio.h>
#include <stdlib.h>

void Validate(char* Str);

int main(){

    char Str[100];
    scanf("%s", &Str[0]);

    Validate(&Str[0]);

    return 0;

}

void Validate(char* Str){

    // Creating a Stack with a Single Element
    char* Stack = (char*)malloc(1); 
    
    // Intializing the Length of the Stack to be 1
    int Len = 1; 
    
    // Initializing the First Element of the Stack to the null character
    *Stack = '\0'; 

    while(*Str!='\0'){

        // Checking whether the Character is a Bracket
        if (*Str==40 || *Str==41 || *Str==91 || *Str==93 || *Str==123 || *Str==125){

            // Checking whether the Opening Bracket and Closing Bracket are matching
            if((*Str==*(Stack+Len-1)+1) || (*Str==*(Stack+Len-1)+2)){ 

                if(Len>1){

                    // Removing the matching bracket and reducing the Length by 1
                    Stack = (char*)realloc(Stack, --Len); 

                }
                
                else{

                    *Stack = '\0';

                }

            }

            else{

                // Pushing the unmatched Bracket into the Stack and increasing the Length by 1
                Stack = (char*)realloc(Stack, ++Len); 
                *(Stack+Len-1) = *Str;                

            }

        }

        Str++;

    }

    // Checking If the Stack has only one element which is the null character and no other character
    if(*(Stack+Len-1)=='\0'){ 

        printf("Valid\n");

    }

    else{

        printf("Invalid\n");

    }

}
