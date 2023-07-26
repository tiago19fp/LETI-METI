#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char const *argv[]) {
  int numer[10];

  fill(numer, 10, 35);
  for (size_t i = 0; i < 10; i++) {
    printf("%d\n",numer[i]);
  }
  return 0;
}
