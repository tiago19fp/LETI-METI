#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,1,2};
    int arrsize = sizeof(arr)/sizeof(int);
    int start, end;
    int fd[2];
    int sum=0;

    if(pipe(fd) == -1){
        perror("Ardeu");
    }

    int id = fork();

    if(id == 0){
        start = 0;
        end = arrsize/2;
    }else
    {
        start = arrsize/2;
        end = arrsize;
    }

    for(int i = start; i<end; i++){
        sum += arr[i];
    }
    
    printf("Soma parcial:%d\n", sum);

    if(id == 0){
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    }else{
        int sumt = 0;
        close(fd[1]);
        read(fd[0], &sumt, sizeof(int));
        close(fd[0]);
        printf("Soma total: %d\n", sumt+sum);
        wait(NULL);
    }
    


 }
