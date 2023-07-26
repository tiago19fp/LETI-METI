#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    float b;

    printf("Digite o salario:\n");
    scanf("%d",&a);

    if(a==0){

        printf(" Vai trabalhar !\n");

    }else if(a>1000){

        b=a*0.10;

        printf("Voce vai pagar %.2f de impostos", b);

    }else if(a<=1000){

        b=a*0.05;

        printf("Voce vai pagar %.2f de impostos", b);

    }
    getch();
    return 0;
}
