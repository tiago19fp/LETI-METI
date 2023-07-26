#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define NFILHOS 10

int main(int argc, char const *argv[]) {
  int i;
  pid_t pid;

  for ( i = 0; i != NFILHOS && (pid=fork() == 0); i++) {
      if(i != NFILHOS){
        printf("pidFilho = %d, Pidpai = %d\n",getpid(), getppid());
      }
  }
  _exit(1);
    return 0;
}
