#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

  //int pid = fork();

  if(fork()==0){
      int file = open("boas.txt", O_WRONLY|O_CREAT, 0666);
      printf("OLA\n");
      dup2(file,1);
      close(file);
      execlp("ls", "ls", NULL);

  }else{
    wait(NULL);
    printf("boas\n");
  }

  return 0;
}
