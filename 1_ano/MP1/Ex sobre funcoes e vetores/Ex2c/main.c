#include <stdio.h>
#include <stdlib.h>

int caracter(a,b){

    int i=0;
    a++;

    for(i=0;i<b;i++){

        printf("%c\n", a++);

    }

}

int main()
{
    char a=' ';
    int b=0;

    printf("Escreva um caracter:");
    scanf("%c",&a);
    scanf("%d", &b);
    caracter(a,b);

    return 0;
}
