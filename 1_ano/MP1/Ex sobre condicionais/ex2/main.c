#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("Escreva um numero:\n");
    scanf("%d",&a);

    if (a>=0){

            printf("O seu numero e positivo");
    }else{

    printf("O seu numero e negativo");

    }

    getch();
    return 0;
}
