#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int num=0;
    int numIntro=0;
    int jogadas=1;

    srand(time(NULL));

    num=1+(rand()%100);

    printf("Tente adivinhar o meu numero.\nEncontra se entre 1 e 100\n");

    while(num!=numIntro){

                printf("Escreva um numero:");
                scanf("%d", &numIntro);


                if(numIntro<num){

                    printf("\nO meu numero e maior.\n");
                    jogadas++;

            }else if(numIntro>num){

                        printf("\nO meu numero e menor\n");
                        jogadas++;
            }

    }


    printf("\njogadas %d", jogadas);

    getch();
    return 0;
}
