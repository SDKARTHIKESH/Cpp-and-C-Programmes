#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	pid_t a, b, c;

	a = fork();

	if(a == 0){

        printf("Parent Process: %d\n", getppid());
        printf("Process a: %d\n", getpid());

		b = fork();

        if(b == 0){
			
			printf("Parent Process: %d\n", getppid());
            printf("Process b: %d\n", getpid());

            c = fork();

            if(c == 0){

                printf("Parent Process: %d\n", getppid());
                printf("Process c: %d\n", getpid());

            } else wait(NULL);

		} else wait(NULL);
		
	} else wait(NULL);

	return 0;

}
