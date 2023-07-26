#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

    int n;
    char buff[128];

    int file2 = open("erros.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    dup2(file2,2);
    close(file2);

    int fd = open("pass.txt", O_RDONLY);
    if(fd == -1){
      perror("ta algo mal crl\n");
      exit(-1);
    }
    dup2(fd,0);
    close(fd);

    int file = open("saida.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    dup2(file,1);
    close(file);

    if (fork()==0) {
      printf("STDIN:%d STDOUT:%d STDERR:%d\n", fd, file, file2);
      n = read(0, buff,128);
      write(1, buff, n);
      write(2, buff, n);
    }
    return 0;
}
