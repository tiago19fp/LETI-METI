#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numseq=0;
    int dado1;
    int dado2;
    int dado3;
    int dado4;
    int dado5;

    srand(time(NULL));


   do{

                dado1=1+(rand()%6);
                dado2=1+(rand()%6);
                dado3=1+(rand()%6);
                dado4=1+(rand()%6);
                dado5=1+(rand()%6);

                numseq++;



   } while(dado1!=dado2 && dado2!=dado3 && dado3!=dado4 && dado4!=dado5 &&  dado1!=dado3 && dado1!=dado4 && dado1!=dado5 && dado2!=dado4 && dado2!=dado5 && dado3!=dado4 && dado3!=dado5 );







        printf("%d  %d  %d  %d  %d\n", dado1,dado2,dado3,dado4,dado5);

        printf("%d seq",numseq);





    return 0;
}
