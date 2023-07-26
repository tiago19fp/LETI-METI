#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int a;
    int i=0;

    srand(time(NULL));

    a=rand()%2;

for(i=0; i<10;i++){
         a=rand()%2;
        if(a==1){

            printf("Cara\n");

        }else{

          printf("Coroa\n");

          }
}

    getch();
    return 0;
}
