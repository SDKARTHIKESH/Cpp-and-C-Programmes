#include <stdio.h>

void swap(int *src, int *dest);

int main(){

	int len;
	scanf("%d", &len);
	
	int arr[len][3];
	int res[len][4];

	for(int x  = 0; x < len; x++){
		
		scanf("%d", &arr[x][0]);
		scanf("%d", &arr[x][1]);
		scanf("%d", &arr[x][2]);

	}

	for(int x = 0; x < len - 1; x++){
		
		for(int y = 0; y < len - x - 1; y++){

			if(arr[y][1] == arr[y + 1][1] && arr[y][0] > arr[y + 1][0]){

				swap(&arr[y][0], &arr[y + 1][0]);
				swap(&arr[y][1], &arr[y + 1][1]);
				swap(&arr[y][2], &arr[y + 1][2]);

			}	

		}	

	}	

	for(int x = 0; x < len; x++){

		if(x == 0) res[x][0] = arr[x][2];
		else{
			
		 	if(res[x-1][0] >= arr[x][1]) res[x][0] = res[x-1][0] + arr[x][2];
			else res[x][0] = arr[x][1] + arr[x][2];

		}

		res[x][1] = res[x][0] - arr[x][1];
		res[x][2] = res[x][1] - arr[x][2];
		res[x][3] = res[x][2];

	}

	for(int x = 0; x < len; x++){

		printf("PID: %d, CT: %d, TAT: %d, WT: %d, RT: %d\n", arr[x][0], res[x][0], res[x][1], res[x][2], res[x][3]);

	}

	return 0;

}

void swap(int *src, int *dest){

	int temp = *src;
	*src = *dest;
	*dest = temp;

	return;

}
