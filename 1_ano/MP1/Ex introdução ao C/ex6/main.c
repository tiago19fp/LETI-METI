#include <stdio.h>
#include <stdlib.h>

int main( ){

   float a,b,A;

   printf("digite a base: ");
   scanf("%f",&a);

   printf("digite a altura: ");
   scanf("%f", &b);

   A=2*3.14*a*(a+b);
   printf("a area e: %f",A);

    getch();

    return 0;
}
