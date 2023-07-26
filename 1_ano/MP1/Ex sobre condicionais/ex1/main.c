#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;

    printf("Introduza um numero:\n");
    scanf("%f",&a);
    printf("Parte inteira:%d\n", (int)a);
    printf("Parte decimal:%f\n", a-(int)a);

    getch();
    return 0;

}
