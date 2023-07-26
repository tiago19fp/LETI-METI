#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra1 =' ';
    char letra2 = ' ';

    printf("Escreva as duas letras:\n");
    scanf("%c %c",&letra1,&letra2);
    printf("-----------------------------\n");

    if(letra1<letra2){

        letra1++;

        while(letra1<letra2){

                    printf("%c\n",letra1);
                    letra1++;

        }

    }else if(letra1==letra2) {

                printf("As duas letras sao iguais!");

    } else{

                 letra1--;

                while(letra1>letra2){

                            printf("%c\n",letra1);
                            letra1--;

            }

}

    getch();
    return 0;
}
