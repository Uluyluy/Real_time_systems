#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void ctrl_c_handler(int signum) {
    printf("\nCaught Ctrl+C (SIGINT). Process will now terminate gracefully.\n");
    exit(0);
}

int main() {
    signal(SIGINT, ctrl_c_handler);

    printf("Process started. Press Ctrl+C to stop.\n");
    
    while(1) {
        printf("Working...\n");
        sleep(2);
    }
    return 0;
}