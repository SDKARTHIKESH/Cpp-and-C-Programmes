/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{

    char Name[50];
    int Salary;

};

void Insert(struct Employee *Arr, int *Size, char *Name, int Salary);
void Delete(struct Employee *Arr, int *Size, char *Name);

int main(){

    int Len;
    scanf("%d", &Len);

    struct Employee *Arr = (struct Employee *)malloc(Len*sizeof(struct Employee));

    for(int x = 0; x < Len; x++){
        printf("Hello\n");
        
        scanf("%s", &(((Arr+x)->Name)[0]));
        scanf("%d", &((Arr+x)->Salary));

    }

    for(int x = 0; x < Len; x++){

        printf("%s, %d\n", &((Arr+x)->Name)[0], (Arr+x)->Salary);

    }

    char Name[50];
    int Salary;

    scanf("%s", &Name[0]);
    scanf("%d", &Salary);

    Insert(Arr, &Len, &Name[0], Salary);

    for(int x = 0; x < Len; x++){

        printf("%s, %d\n", &((Arr+x)->Name)[0], (Arr+x)->Salary);

    }

    scanf("%s", &Name[0]);

    Delete(Arr, &Len, &Name[0]);

    for(int x = 0; x < Len; x++){

        printf("%s, %d\n", &((Arr+x)->Name)[0], (Arr+x)->Salary);

    }

    return 0;

}

void Insert(struct Employee *Arr, int *Size, char *Name, int Salary){

    Arr = (struct Employee *)realloc(Arr, ++(*Size));

    int Index = 2;
    
    struct Employee New = {*Name, Salary};
    struct Employee Temp1 = *(Arr+Index);
    struct Employee Temp2;
    *(Arr+Index) = New;

    for(int x = Index+1; x < *Size; x++){

        Temp2 = *(Arr + x);
        *(Arr + x) = Temp1;
        Temp1 = Temp2;

    }

    return;

}

void Delete(struct Employee *Arr, int *Size, char *Name){

    int Index;

    for(Index = 0; strcmp(&((Arr+Index)->Name)[0], Name) == 0; Index++);

    for(int x = Index+1; Index < *Size; Index++){

        *(Arr + x - 1) = *(Arr + x);

    }

    Arr = (struct Employee *)realloc(Arr, --(*Size));

    return;

}*/

#include <stdio.h>

int main(){

    char c1 = 'a';
    char c2 = 12;

    printf("%c\n", c1+c2);


    return 0;

}