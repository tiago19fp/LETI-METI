#include <stdio.h>
#include <stdlib.h>

int main(){

       int i=0;
       int j=0;
       int k=0;
       int soma=0;
       int media=0;
       int max=0;
       int per=0;
       float max90=0;
       int vet[i];
       int vet2[k];

        printf("Tamanho da sequencia:");
        scanf("%d",&j);
        printf("Escreva o vetor:\n");

       for(i=0;i<j;i++){

             scanf("%d",&vet[i]);
             soma= soma + vet[i];

      }

       media= soma/j;

       for(i=0;i<j;i++){

             if(vet[i]>media){

                 vet2[k]=vet[i];
                 k++;
             }
       }

       for(i=0;i<j;i++){

              if(vet[i]>max) {

                max= vet[i];

              }
       }

        printf("\n-----------vetor---------------\n");

         for(i=0;i<j;i++){

                printf("%d\n",vet[i]);

         }

          printf("\n-------vetorSuperiorMedia------\n");

          for(i=0;i<k;i++){

                printf("%d\n",vet2[i]);

         }

         per=k*100/j;
         max90=0.9*max;

         printf("\n-------------------------------\n");

         printf("media=%d   Maximo=%d   Maximo90=%.3f  Perc/superiorMedia=%d", media, max,max90, per);


        getch();
        return 0;
}

