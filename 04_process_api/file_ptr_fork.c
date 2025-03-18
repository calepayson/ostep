#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd = open("TEST.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int pid = fork();
    if (pid < 0) {  // Forking error
        fprintf(stderr, "Oh fork...\n");
        exit(1);
    } else if (pid == 0) {  // Child process
        const char *text = "Hello, world!\n";
        write(fd, text, strlen(text));
    } else {  // Parent process
        const char *text = "Goodybe, cruel world!\n";
        write(fd, text, strlen(text));
    }

    close(fd);

    return 0;
}
