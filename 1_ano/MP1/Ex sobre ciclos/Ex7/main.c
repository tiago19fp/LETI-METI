#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int a=0;
    int b=1;
    int c;

    printf("Escolha a tabuada desejada:\n");
    scanf("%d",&a);
    printf("------------------\n");
    c = a+0;

    while(i<10){

        a   = a*b;
        b++;
        printf("%d\n",a);
        a = c+0;
        i++;
    }

    getch();
    return 0;
}
