#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    union Hello {

        float a;
        int b;

    };

    union Hello* Arr = (union Hello*)malloc(5 * sizeof(union Hello));

    //scanf("%f", &(Arr->a));
    //scanf("%d", &(Arr->b));

    printf("%f\n", Arr->a);
    printf("%d\n", Arr->b);

    return 0;
}