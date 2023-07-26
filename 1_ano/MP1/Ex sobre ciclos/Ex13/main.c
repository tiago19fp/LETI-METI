#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b=1;
    int c=0;
    int aux;
    int i;
    printf("Escreva o numero:\n");
    scanf("%d",&a);
    printf("-----------\n");
    printf("Serie de Fibonacci:\n");

    for(i=0; i<a;i++){

        aux= c+b;
        c=b;
        b=aux;

        printf("%d\n",aux);


    }

    getch();
    return 0;
}
