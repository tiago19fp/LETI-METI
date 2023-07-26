#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0;
    int a=0;
    int QN=0;
    int Max=0;

    printf("Quantos numeros?\n");
    scanf("%d",&QN);

    while(i<QN){

        printf("Escreva um numero:\n");
        scanf("%d",&a);

        if(a>Max){

            Max=a;
        }

    i++;

    }

    printf("Maximo:%d\n",Max);
    getch();
    return 0;
}
