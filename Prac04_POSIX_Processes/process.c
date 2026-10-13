/* ----------------------------------------------------*/
/* ИМЯ: Пронкина Тамара Павловна ID пользователя: Uluyuluy */
/* СРОК : 17/09/2026 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ #4 */
/* ИМЯ ФАЙЛА: process.c */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ: Создание родительского и дочернего */
/* процессов с использованием fork() */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
/* #include <sys/types.h> */

#define MAX_COUNT 200

void  ChildProcess(void){
    int i = 1;
    while(i <= MAX_COUNT){
        printf("   This line is from child, value = %d\n", i);
        i++;
    }
    printf("Child process %d terminates.\n", getpid());
}


void  ParentProcess(void){
    int i = 1;
    while(i <= MAX_COUNT){
        printf("   This line is from parent, value = %d\n", i);
        i++;
    }
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
