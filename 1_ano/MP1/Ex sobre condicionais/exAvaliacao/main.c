#include <stdio.h>
#include <stdlib.h>

int main()
{
    int consumo=10;
    float preco_por_hora_watt=0.10;
    int dias=0;
    int resultado=0;
    int horasCons=0;

    printf("Quantos dias:\n");
    scanf("%d",&dias);

    horasCons=(dias*24/1)*10;
    resultado= horasCons*preco_por_hora_watt;

    printf("%d euros",resultado);

    return 0;
}
