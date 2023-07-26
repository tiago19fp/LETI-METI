#include <stdio.h>
#include <stdlib.h>

int main(){

       int i;
       int j;
       int aux  ;
       int numero[10];

       for(i=0;i<10;i++){

              scanf("%d", &numero[i]);

       }

              for( i=0; i<10; i++ ){

                     for( j=i+1; j<10; j++ ){

                           if( numero[i] > numero[j] ){

                              aux = numero[i];
                              numero[i] = numero[j];
                              numero[j] = aux;
                          }
                     }
                }

                for(i=0;i<10;i++){

                      printf("%d   ",numero[i]);

                }

}
