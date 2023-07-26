#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include "stdio.h"

ssize_t readln(int fd, char *line, size_t size){

  int i = 0, n;
  while (i<size && (n = read(fd, &line[i], 1)) == 1 && line[i] != '\n') {
    i++;
  }
  if(n == -1) return i> 0 ? i : -1;
  return n == 0 ? : i+1;
}

int main(int argc, char const *argv[]) {

  char t[4096];
  int n;

  int fd = open(argv[1], O_RDONLY);

  if (fd<0) {
    perror("Falta alguma coisa");
    return -1;
  }
int i=0;
n = readln(0,t,sizeof(t));
write(STDOUT_FILENO, t, n);
close(fd);
  return 0;
}
