#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int a;
    int cont=0;
    int dado1;
    int dado2;
    int dado3;
    int dado4;
    int dado5;
    int dado6;

    srand(time(NULL));

    while(a){

        dado1= 1+rand()%6;
        dado2= 1+rand()%6;
        dado3= 1+rand()%6;
        dado4= 1+rand()%6;
        dado5= 1+rand()%6;
        dado6= 1+rand()%6;

        if(dado1==dado2 && dado2==dado3 && dado3==dado4 && dado4==dado5 && dado5==dado6){

            break;

        }

          cont++;
    }

        printf("%d %d %d %d %d %d\n seq=%d",dado1,dado2,dado3,dado4,dado5,dado6, cont);

    getch();
    return 0;
}
