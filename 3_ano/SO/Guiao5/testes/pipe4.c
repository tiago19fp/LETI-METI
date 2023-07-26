#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int fd[2];


    if (pipe(fd) == -1)
    {
        perror("Ardeu");
    }

    if (fork() == 0)
    {
        close(fd[0]);
        char str[100];
        fgets(str, 100, stdin);
        write(fd[1], str, strlen(str)+1);
        close(fd[1]);
    }else{
        close(fd[1]);
        char strout[100];
        read(fd[0], strout, sizeof(strout)+1);
        close(fd[0]);
        printf("%s", strout);

    }
    
    return 0;
}
