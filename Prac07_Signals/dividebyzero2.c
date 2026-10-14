#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_dividebyzero(int signum);

int main() {
    int result;
    int v1 = 121;
    int v2 = 0;
    void (*sigHandlerReturn)(int);

    /* Устанавливаем наш обработчик для сигнала SIGFPE */
    sigHandlerReturn = signal(SIGFPE, handler_dividebyzero);
    
    if (sigHandlerReturn == SIG_ERR) {
        perror("Signal Error: ");
        return 1;
    }

    result = v1 / v2; /* Здесь возникнет сигнал SIGFPE */
    
    /* Эта строка не выполнится, так как обработчик вызовет exit(0) */
    printf("Result of Divide by Zero is %d\n", result);
    return 0;
}

void handler_dividebyzero(int signum) {
    if (signum == SIGFPE) {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0); /* Корректное завершение программы */
    } else {
        printf("Received %d Signal\n", signum);
    }
}