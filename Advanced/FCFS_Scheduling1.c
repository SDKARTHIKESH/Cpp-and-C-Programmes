#include <stdio.h>

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

	for(int x = 0; x < len; x++){

		if(x == 0) res[x][0] = arr[x][2];
		else res[x][0] = res[x-1][0] + arr[x][2];

		res[x][1] = res[x][0] - arr[x][1];
		res[x][2] = res[x][1] - arr[x][2];
		res[x][3] = res[x][2];

	}

	for(int x = 0; x < len; x++){

		printf("CT: %d, TAT: %d, WT: %d, RT: %d\n", res[x][0], res[x][1], res[x][2], res[x][3]);

	}

	return 0;

}
