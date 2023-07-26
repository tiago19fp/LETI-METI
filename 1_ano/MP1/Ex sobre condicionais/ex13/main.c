#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a;

    printf("Escreva o ano:\n");
    scanf("%d", &a);

    if(a%4==0 &&(a%400==0 || a%100!=0)){

        printf("O ano e bissexto.");

    }else{

        printf("O ano nao e bissexto.");

    }


    getch();
    return 0;
}
