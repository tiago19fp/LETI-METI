#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

    int file2 = open("erros.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    dup2(file2,2);
    close(file2);
    
    int file = open("saida.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    dup2(file,1);
    close(file);

    int fd = open("pass.txt", O_RDONLY);
    if(fd == -1){
      perror("ta algo mal \n");
      exit(-1);
    }
    dup2(fd,0);
    close(fd);

    execlp("wc","wc",NULL);

    return 0;
}
