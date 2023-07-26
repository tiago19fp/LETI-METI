#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int a=0;
    int c=0;

    while(i<20){

        printf("Escreva um numero:\n");
        scanf("%d", &a);
        c= c +a ;
        i++;
        }
        printf("soma: %d", c);

    getch();
    return 0;
}
