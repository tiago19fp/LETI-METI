#include <stdio.h>
#include <stdlib.h>

int main(){

       int i;
       int vet[ 12];
       int soma=0;

       for(i=0;i<12;i++){

              scanf("%d",&vet[i]);

       }

        for(i=0;i<12;i++){

               printf("%d\n",vet[i]);
               soma=soma +vet[i];

        }

        printf("Total:%d",soma);

        getch();
        return 0;
}
