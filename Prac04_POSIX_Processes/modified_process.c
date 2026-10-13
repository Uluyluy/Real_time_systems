/* ----------------------------------------------------*/
/* ИМЯ: Пронкина Тамара Павловна ID пользователя: Uluyuluy */
/* СРОК : 17/09/2026 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ #5 */
/* ИМЯ ФАЙЛА: process.c */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ: Создание родительского и дочернего */
/* процессов с использованием fork() */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

void  ChildProcess(void){
    printf("Child process %d starts ", getpid());
    char *args[] = {"date", NULL};
    execvp("date", args);
    printf("Child process %d terminates.\n", getpid());
}


void  ParentProcess(void){
    printf("Parent process %d starts ", getpid());
    sleep(2);
    printf("Parent process %d terminates.\n", getpid());
}


int main(){
    int pid;
    printf("Original process with pid %d and ppid %d\n", getpid(), getppid());
    
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0 ){
        ChildProcess();
    }
    else{
        ParentProcess();
    }

     return 0;
}
