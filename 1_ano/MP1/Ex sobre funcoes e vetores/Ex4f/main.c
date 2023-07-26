#include <stdio.h>
#include <stdlib.h>

int main(){

        int i=0;
        int k=0;
        int p=0;
        int b=0;
        int tam=0;
        int vet[tam];
        int vetPares[p];
        int vetImapares[b];

        printf("Escreva o tamanho da sequencia:");
        scanf("%d",&tam);

        for(i=0;i<tam;i++){

                scanf("%d", &vet[i]);

        }


        for(i=0;i<tam;i++){

            if( vet[i]%2==0){

                vetPares[b]= vet[i];
                b++;

            }else{
                  vetImapares[p]= vet[i];
                  p++;

            }

        }


        if(b<p){

            for(i=0; i<b;i++){

                 vet[i]=vetPares[i];


            }
            b++;
            p--;

            for(i=b;i<p;i++){

                vet[i]= vetImapares[i];


            }




        }



        else if(b>p){

            for(i=0; i<p;i++){

                 vet[i]=vetPares[i];


            }
            p++;
            b--;

            for(i=p;i<b;i++){

                vet[i]= vetImapares[i];


            }

        }

        for(i=0;i<tam;i++){

            printf("%d   ", vet[i]);


        }
}

