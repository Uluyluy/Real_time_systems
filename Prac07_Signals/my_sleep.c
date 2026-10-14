#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

static unsigned int remaining_alarm = 0;

void sig_alrm(int signo) {
}

unsigned int mysleep(unsigned int nsecs) {
    struct sigaction newact, oldact;
    unsigned int unslept;

    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);
    remaining_alarm = alarm(nsecs);
    pause();
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    
    return unslept;
}

int main() {
    printf("Sleeping for 5 seconds using custom mysleep...\n");
    unsigned int left = mysleep(5);
    printf("Woke up. Unslept time: %u seconds\n", left);
    
    return 0;
}