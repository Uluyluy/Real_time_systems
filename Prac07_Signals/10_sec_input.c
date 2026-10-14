#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t alarm_triggered = 0;

void alarm_handler(int signum) {
    alarm_triggered = 1;
}

int main() {
    char input[100];
    signal(SIGALRM, alarm_handler);
    alarm(10);
    printf("Enter something within 10 seconds: ");
    fflush(stdout);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        alarm(0); 
        if (!alarm_triggered) {
            printf("Thank you! You entered: %s", input);
        } else {
            printf("No input (timeout occurred just as you typed).\n");
        }
    } else {
        if (alarm_triggered) {
            printf("No input\n");
        } else {
            printf("Error reading input.\n");
        }
    }
    return 0;
}