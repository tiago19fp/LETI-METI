#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  printf("pai: pid: %d, ppid: %d\n", getpid(), getppid());
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }
  puts("ola");
  if (pid == 0) { /* filho */
    printf("filho: pid: %d, ppid: %d\n", getpid(), getppid());
    return 1;
  }else{ /* pai */
    printf("pai: pid: %d, ppid: %d, filho =%d\n", getpid(), getppid(), pid);
  }
  return 0;
}
