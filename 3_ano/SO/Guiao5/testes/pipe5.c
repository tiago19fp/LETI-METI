#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    pipe(fd);
    int pid1 = fork();
    if(pid1 == 0){
        close(fd[0]);
        dup2(fd[1],1);
        close(fd[1]);
        execlp("ls", "ls", "/etc", NULL);
    }else{
    
    //int pid2 = fork();
    wait(NULL);
    //if(pid2 == 0){
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execlp("wc", "wc", "-l", NULL);
    //}
    close(fd[0]);
    close(fd[1]);
    //waitpid(pid1, NULL, 0);
    //waitpid(pid2, NULL, 0);
    }
    return 0;
}
