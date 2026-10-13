#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid;
    printf("I`m the original process with pid %d and ppid %d\n", getpid(), getppid());
    /* На этом моменте родительскому и дочернему процессу возвращаются разные pid
       и каждый процесс продолжает выполнение со своим pid сохраненнным в переменной */
    pid = fork();

    if (pid!=0){
        printf("I'm the parent process with pid %d and ppid %d\n", getpid(), getppid());
        printf("my child's pid is %d\n", pid);
    }
    else{/* esli pid==0, this is child process*/
        printf("I'm the child process with pid %d and ppid %d\n", getpid(), getppid());
    }
    printf("pid %d terminates.\n", getpid());
    return 0;
}
