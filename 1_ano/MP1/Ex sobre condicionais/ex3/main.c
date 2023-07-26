#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b;

    printf("Escreva  um numero:\n");
    scanf("%d", &a);
    printf("Escreva  um numero:\n");
    scanf("%d", &b);

    if(a>b){

            printf(" %d>%d", a,b);

    }else if (a<b){

        printf(" %d<%d", a,b);

    }else if(a=b){

        printf(" %d=%d", a,b);

}
    getch();


return 0;
}
