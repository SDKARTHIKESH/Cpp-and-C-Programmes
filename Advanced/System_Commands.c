#include <stdio.h>
#include <stdlib.h>

int main() {

    int status;

    printf("Executing 'ls -l' command:\n");
    printf("The ls -l command in bash lists the files and directories in the current directory in long format.\n\n");

    status = system("ls -l");

    if (status == -1) {

        printf("Failed to execute 'ls -l' command\n");
        exit(1);

    }

    printf("\nExecuting 'pwd' command:\n");
    printf("The pwd command in bash prints the current working directory.\n\n");

    status = system("pwd");

    printf("\n");

    if (status == -1) {

        printf("Failed to execute 'pwd' command\n");
        exit(1);

    }

    return 0;

}