#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    int b=0;
    int c=0;

    printf("Escreva dois numeros:\n");
    scanf("%d %d", &a,&b);

    c= a*b;

    printf("A multiplocao dos dois numero e:%d\n", c);
    return 0;
}
