#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(int argc, char const *argv[])
{
    mkfifo("myfiffo1", 0777);
    int fd = open("myfiffo1",O_WRONLY);
    int x = 97;
    write(fd, &x, sizeof(x));
    close(fd);
    return 0;
}
