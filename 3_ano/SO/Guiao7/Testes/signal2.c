#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    int pid = fork();

    if(pid == 0){
        while(1){
        printf("BOAS MIUDO\n");
        }
    }
    kill(pid, SIGSTOP);
    int t;
    do
    {
        printf("\nHow many seconds:");
        scanf("%d", &t);
        kill(pid,SIGCONT);
        sleep(t);
        kill(pid,SIGSTOP);
    
    } while (t > 0);
    
    kill(pid, SIGKILL);
    wait(NULL);

    return 0;
}
