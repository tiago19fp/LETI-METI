#include <stdio.h>
#include <stdlib.h>

int fatorial(a){

    int i;
    int fatorial;

    fatorial=a;

    for(i=1;i<a;i++){

        fatorial=fatorial * i;

    }

    printf("fatorial:%d",fatorial );

}

int main()
{
    int a=0;

    printf("Escreva um numero:");
    scanf("%d",&a);

    fatorial(a);

    return 0;
}
