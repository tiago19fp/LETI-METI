#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char const *argv[]) {

    pid_t pid = fork();

    if(pid==0){
      execlp("ls","ls","-l", NULL);
      _exit(1);
    }
    wait(NULL);
    printf("ola crl!\n");
  return 0;
}
