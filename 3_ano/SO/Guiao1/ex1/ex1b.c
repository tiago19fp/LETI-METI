#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define  SIZE 4096

int main(int argc, char const *argv[]) {

  char c[SIZE];
  int n;

  // validar args

  int f = open(argv[1], O_RDONLY);
  //validar if f == -1 exit, perror("erro no open fich origem"), exit(-1)

  int d = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0700);
  //validar

  while ((n = read(f, c, SIZE)) > 0) {

    write ( d, c, n);

  }

  return 0;
}
