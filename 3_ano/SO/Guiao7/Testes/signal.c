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
            printf("Boas\n");
        }
    }
    sleep(1);
    kill(pid, SIGSTOP);
    sleep(1);
    kill(pid, SIGCONT);
    sleep(1);
    kill(pid, SIGKILL);
    wait(NULL);
    return 0;
}
