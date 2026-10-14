#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int fd;
volatile sig_atomic_t interrupted = 0;

void onintr(int sig) {
    char answer;
    signal(SIGINT, onintr);
    printf("\nInterrupted! Continue? (y/n/r): ");
    fflush(stdout);
    scanf(" %c", &answer);
    if (answer == 'n') {
        printf("Exiting program.\n");
        exit(0);
    } else if (answer == 'r') {
        lseek(fd, 0L, SEEK_SET);
        printf("Restarting from beginning.\n");
    } else {
        printf("Continuing...\n");
    }
    interrupted = 0; 
}

int main() {
    char buffer[256];
    ssize_t bytes_read;
    fd = open("/etc/termcap", O_RDONLY);
    if (fd < 0) {
        printf("File /etc/termcap not found. Using /etc/passwd for demonstration.\n");
        fd = open("/etc/passwd", O_RDONLY);
        if (fd < 0) {
            perror("Error opening file");
            return 1;
        }
    }
    signal(SIGINT, onintr);

    printf("Reading file. Press Ctrl+C to interact.\n");

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        usleep(10000);
    }

    close(fd);
    printf("\nFile reading completed.\n");
    return 0;
}