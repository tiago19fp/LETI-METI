#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {

/*size_t pro;
int status;
for (size_t i = 0; i < 10; i++) {
    pro = fork();
    if(pro == 0){
     printf("Sou filho : %d pid:%d Pai:%d\n", i, getpid(), getppid());
    _exit(1);
    }
    //wait(NULL);
    printf("Ola\n");
    pid_t pid;
    pid = wait(&status);
    for (size_t j = 0; j < 10; j++) {
      if(WIFEXITED(status)){
      printf("%d\n", WEXITSTATUS(status));
    }
    }
  }*/

  //return 0;
  pid_t pid;
  for (size_t i = 0; (pid =fork()) == 0 && i < 10; i++) {
    if(i!=10){
       printf("Sou filho : %d pid:%d Pai:%d\n", i, getpid(), getppid());
     }
    }
    wait(NULL);
    if(pid !=0 ){
    printf("ola\n" );
    }
    return 0;

}
