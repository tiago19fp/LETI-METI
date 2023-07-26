#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;

    printf("Escreva uma letra:\n");
    scanf("%c",&a);

    printf("%c %c %c %c \n", a+1, a+2, a+3, a+4);
    return 0;
}
