#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int soma;
    int mul;

    scanf("%d %d",&a,&b);

    soma= a+b;
    mul= a*b;

    a=2*a;
    b=2*b;

    printf("soma=%d  multiplicacao:%d  dobro= %d %d",soma,mul,a,b);


    return 0;
}
