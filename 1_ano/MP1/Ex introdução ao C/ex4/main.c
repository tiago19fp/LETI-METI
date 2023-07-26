#include <stdio.h>
#include <stdlib.h>

int main()
{

    int minutosIntro;
    int dias;
    int horas;
    int minutos;

    printf("minutos:\n");
    scanf("%d",&minutosIntro);

    horas= (minutosIntro/60)%24;
    minutos= minutosIntro%60;
    dias= minutosIntro/1440;



   printf("dias:%d  horas:%d  minutos:%d", dias,horas,minutos);

 return 0;
}
