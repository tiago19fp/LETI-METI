#include <stdio.h>
#include <stdlib.h>

int simetrico(a){

        a=-a;

        printf("simetrico:%d",a);

}


int main()
{
    int a=0;

    printf("Escreva um numero:");

    scanf("%d", &a);

    simetrico(a);

    return 0;
}
