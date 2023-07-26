#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define NFILHOS 10

void ultimas_palavras(void) {
  printf("Adeus mundo cruel!\n");
}

void sou_imortal() {
  printf("ha, ha, ha, sou imortal!\n");
  while(1);
}
int main(int argc, char const *argv[]) {
  int i, status;
  for (i = 0; i != 10; i++) {
      pid_t pid, pidl;
      pid = fork();
      switch (pid) {
        case -1: //erro
                perror("fork");
                return 1;
        case 0: //filhos
                //atexit(sou_imortal);
                printf("filho i = %d, pid = %d, ppid = %d\n", i, getpid(), getppid());
                printf("Vou morrer\n");
                //exit(i+1);
                _exit(i+1); //mata sempre o programa
        default: //pai
                printf("criado pid = %d\n", pid);
                //pidl = wait(NULL);
                pidl = wait(&status);
                printf("morreu pid = %d\n", pidl);
                if(WIFEXITED(status)){
                  printf("exit: %d\n", WIFEXITED(status));
                }else{
                  printf("filho nao terminou com exit\n");
                }
      }
  }
  return 0;
}
