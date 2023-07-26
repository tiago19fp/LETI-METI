#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sexo=0;
    int Sal=0;
    int Imp=0;

    printf("Se for mulher escreva 1 , se for homem escreva 2\n");
    scanf("%d",&sexo);
    printf("Escreva o seu salario:\n");
    scanf("%d",&Sal);

    if( sexo==1){

        Imp= Sal*.05;


    }else{

        Imp=Sal*.10;

}

        printf("Vai pagar %d de imposto", Imp);

    return 0;
}
