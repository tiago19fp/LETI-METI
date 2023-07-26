#include <stdio.h>
#include <stdlib.h>

int main()
{
        float MinIntr;
        float  Dias;
        float  Horas;
        float  Minutos;
        float Resto1;
        float Resto2;

        printf("Escreva os minutos:\n");
        scanf("%f", &MinIntr);

        Dias = MinIntr/1440;
        Resto1 = Dias - (int)Dias;

        Horas = Resto1*24/1;
        Resto2 = Horas - (int)Horas;

        Minutos = Resto2 *60/1;

        printf("%f  Dias %f  Horas %f  Minutos", Dias,Horas, Minutos);

        getch();
        return 0;
}
