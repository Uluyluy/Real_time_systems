#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("I'm process of main program %d and I'm about to exec an ls -l\n", getpid());
    /* истемный вызов execl заменяет текущий образ процесса (эту программу) на новый образ
       — программу /bin/ls с аргументом -l. */
    execl("/bin/ls", "ls", "-l", NULL);
    printf("this is line should be never executed\n");
    return 0;
}
