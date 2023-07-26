#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contador=0;

    scanf("%d", &num);

    if(num==0){

        contador=1;

    }

    while(num!=0){

        contador++;
        num=num/10;

    }

    printf("Digitos:%d", contador);

    return 0;
}
