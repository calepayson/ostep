#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num = 100;

    int pid = fork();
    if (pid < 0) {  // Fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {  // Child process
        printf("Child (%d): num = %d\n", getpid(), num);
        printf("Child (%d): ++num = %d\n", getpid(), ++num);
        exit(0);
    } else {  // Parent process
        printf("Parnt (%d): num = %d\n", getpid(), num);
        printf("Parnt (%d): --num = %d\n", getpid(), --num);
    }

    return 0;
}
