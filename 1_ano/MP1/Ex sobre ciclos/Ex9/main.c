#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int a=0;
    int somatorio=0;

    for(i=0;i<10;i++){

        printf("Escreva um numero:");
        scanf("%d",&a);

        somatorio = a + somatorio;

    }

    printf("Somatorio:%d",somatorio);

    getch();
    return 0;
}
