#include <stdio.h>

int main(){

    int Units;
    double Total;

    printf("Enter the Number of Units consumed : ");
    scanf("%d", &Units);

    printf("\n");

    if (Units>300){

        Total=(200*1)+(100*1.5)+(Units-300)*2;

    }

    else if (Units<300 && Units>200){

        Total=(200*1)+(Units-200)*1.5;

    }

    else{

        Total=Units*1;

    }

    printf("The Bill Amount is Rs.%lf\n", Total);

    return 0;

}