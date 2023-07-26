#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;
    int cont;
    int pares=0;

    while(cont!=0){

        scanf("%d",&num);

        if(num%2==0 && num!=0){

            pares= pares+1;
            cont = num;

        }else{

              cont = num;
        }
    }

    printf("Pares:%d",pares);

    getch();
    return 0;
}
