#include <stdio.h>
#include <unistd.h>

int main(){

	pid_t a, b;

	a = fork();

	if(a > 0){

		b = fork();

		if(b == 0){
			
			for(int x = 0; x <= 1000; x+=2) printf("%d\n", x);

		}
		
	}


	else if(a == 0){

		for(int x = 1; x <= 1000; x+=2) printf("%d\n", x);

	}

	return 0;

}
