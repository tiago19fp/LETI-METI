#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void fill(int vector[], int size, int value){
  for (size_t i = 0; i < size; i++) {
      vector[i]=value;
    }
}
