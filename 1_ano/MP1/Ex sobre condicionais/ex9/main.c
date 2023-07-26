#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a=' ';
    int salario=0;
    int imposto=0;

    printf("Escreva o seu estado civil:\n");
    scanf("%c", &a);
    printf("Escreva o seu salario:\n");
    scanf("%d",&salario);

    if(a== 'c'){

        imposto =  salario*.10;

    }else if(a=='s'){

        imposto = salario*.09;

    }

    printf("Vai pagar %d de imposto",imposto);

    return 0;
}
