#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include "stdio.h"

ssize_t readln(int fd, char *line, size_t size){
  int n;
  char c;
  int nn=0;

  while((n=read(fd,&c,1))>0){
    *line=c;
    *line++;
    nn++;
    if(c=='\n'){
    nn=0;
    break;
  }
  }
   return nn;
}

int main(int argc, char const *argv[]) {
  char t[4096];
  int n;

  int fd = open(argv[1], O_RDONLY);

  if (fd<0) {
    perror("Falta alguma coisa");
    return -1;
  }

while ((n=readln(fd,t,sizeof(t))>0)){
  //printf("%s\n", t);
  }
  printf("%s\n",t );
  close(fd);
  return 0;
}
