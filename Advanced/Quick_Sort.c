#include <stdio.h>

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void quickSort(int arr[], int start, int end){

    if(end - start <= 1) return;

    int pivot = arr[start];
    int upper = start + 1;
    int lower = start + 1;

    for(int x = start + 1; x < end; x++){

        if(arr[x] > pivot) upper++;

        else{

            swap(&arr[x], &arr[lower]);
            lower++;
            upper++;

        }

    }

    swap(&arr[start], &arr[lower-1]);
    lower--;

    quickSort(arr, start, lower);
    quickSort(arr, lower+1, upper);

    return;

}

int main(){

    int len;
    scanf("%d", &len);

    int arr[len];
    for(int x = 0; x < len; x++) scanf("%d", &arr[x]);

    quickSort(arr, 0, len);

    for(int x = 0; x < len; x++) printf("%d ", arr[x]);
    printf("\n");

}