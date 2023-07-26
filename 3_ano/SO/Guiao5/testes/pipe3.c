#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd1[2]; // P -> C
    int fd2[2]; // C -> P

    if(pipe(fd1) == -1){
        perror("Ardeu");
    }
    if(pipe(fd2) == -1 ){
        perror("Ardeu");
    }

    int pid = fork();

    if(pid == 0){
        close(fd1[1]);
        close(fd2[0]);
        int n;
        read(fd1[0], &n, sizeof(int));
        n = n * 4;
        write(fd2[1], &n, sizeof(int));
        close(fd1[0]);
        close(fd2[1]);
    }else
    {
        close(fd1[0]);
        close(fd2[1]);
        int num = 10;
        write(fd1[1], &num, sizeof(num));
        read(fd2[0], &num, sizeof(int));
        close(fd1[1]);
        close(fd2[2]);
        printf("%d\n", num);
    }
    
    return 0;

 }