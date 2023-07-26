#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>


void handle_sigstop(int sig){
    printf("Nao disponivel\n");
}

int main(int argc, char const *argv[])
{
    int x;

    signal(SIGTSTP, &handle_sigstop);

    scanf("%d", &x);
    
    printf("Dobro: %d\n", x+x);
   
    return 0;
}