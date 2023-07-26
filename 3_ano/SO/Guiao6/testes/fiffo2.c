#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char const *argv[])
{
    mkfifo("myfiffo2", 0777);
    int arr[5];
    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    int fd = open("myfiffo2",O_WRONLY);
        write(fd, arr, sizeof(int)*5);
       close(fd);
    
    return 0;
}
