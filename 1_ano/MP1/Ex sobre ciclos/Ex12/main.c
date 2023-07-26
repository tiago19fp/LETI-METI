#include <stdio.h>
#include <stdlib.h>

int main()
{
        int pares=0;
        int numero=0;

        printf("Escreva um numero:");
        scanf("%d",&numero);

        while(numero!=0){

                    if(numero%2==0){

                        pares=pares+1;

                    }

                    printf("\nEscreva um numero:");
                    scanf("%d",&numero);

        }

        printf("Foram escritos %d pares", pares);

    getch();
    return 0;

}
