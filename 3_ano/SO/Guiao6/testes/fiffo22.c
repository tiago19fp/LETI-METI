#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(int argc, char const *argv[])
{
    int arr[5];
    int fd = open("myfiffo2", O_RDONLY);
     read(fd, arr, sizeof(int)*5);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    close(fd);


    

    return 0;
}
