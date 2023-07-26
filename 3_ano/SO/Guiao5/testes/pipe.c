#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  int fd[2];// fd[0]-read | fd[1]-write
  if(pipe(fd) == -1){
    perror("Ardeu o pipe");
  }

  int pid = fork();
  if(pid == -1){
    perror("Ardeu a criar o processo");
  }
  if(pid == 0){
    close(fd[0]);
    int x;
    printf("Escreve um numero bro: ");
    scanf("%d", &x);
    write(fd[1], &x, sizeof(int));
    close(fd[1]);
  }else{
  close(fd[1]);
  int y;
  read(fd[0], &y,sizeof(int));
  close(fd[0]);
  printf("Numero do processo filho: %d\n", y);
  }
  return 0;
}
