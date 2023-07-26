#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>

int readln(int fd, char *line, int size){
      int n;
      char c;
      int nn=0;

      while((n=read(fd,&c,1))>0){
        *line=c;
        *line++;
        nn++;
        if(c=='\n') break;
      }

      return nn;
}

int main(int argc, char *argv[]){

  int file=open(argv[1],O_RDONLY);
  char buffer[50];
  int n;

  if (file<0){
    perror("open:");
    return -1;
  }

    while((n=readln(file,buffer,sizeof(buffer)))>0){
      write(STDOUT_FILENO,buffer,n);
    }

  close(file);

  return 0;
}
