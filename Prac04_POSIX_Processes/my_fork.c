#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    int i;
    
    printf("Исходный процесс: PID=%d, PPID=%d\n", getpid(), getppid());
    
    pid = fork();
    
    if (pid < 0) {
        perror("Ошибка fork");
        return 1;
    }
    else if (pid == 0) {
        /* Дочерний процесс */
        printf("Дочерний процесс: PID=%d, PPID=%d\n", getpid(), getppid());
        for (i = 1; i <= 3; i++) {
            printf("Дочерний процесс, итерация %d\n", i);
            sleep(2);
        }
        printf("Дочерний процесс завершается\n");
    }
    else {
        /* Родительский процесс */
        printf("Родительский процесс: PID=%d, дочерний PID=%d\n", getpid(), pid);
        for (i = 1; i <= 3; i++) {
            printf("Родительский процесс, итерация %d\n", i);
            sleep(1);
        }
        printf("Родительский процесс завершается\n");
    }
    
    return 0;
}
