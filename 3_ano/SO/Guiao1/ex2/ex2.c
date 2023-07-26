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

  while ((n = read(1, c, SIZE)) > 0) {

    write ( 1, c, n);

  }

  return 0;
}
