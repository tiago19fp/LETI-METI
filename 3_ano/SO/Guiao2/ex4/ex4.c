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
  pid_t pid;
  for (i = 0; i != NFILHOS; i++) { //ciclo criacao filhos
      pid = fork();
      switch (pid) {
        case -1: //erro
                perror("fork");
                return 1;
        case 0: //filhos
                //atexit(sou_imortal);
                printf("filho i = %d, pid = %d, ppid = %d\n", i+1, getpid(), getppid());
                printf("Vou morrer\n");
                //exit(i+1);
                _exit(i+1); //mata sempre o programa
        default: //pai
                printf("criado pid = %d\n", pid);
              }
            }

        for (size_t i = 0; i < NFILHOS; i++) { // ciclo espera pela morte de filhos
          pid = wait(&status);
          printf("morreu pid = %d\n", pid);
          if(WIFEXITED(status)){
            printf("exit: %d\n", WEXITSTATUS(status));
          }else{
            printf("filho nao terminou com exit\n");
          }
        }

  return 0;
}
