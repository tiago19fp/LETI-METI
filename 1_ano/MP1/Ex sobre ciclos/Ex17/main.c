#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a;
    int b;
    int mult1;
    int mult2;

    scanf("%d %d",&a ,&b);

    mult1= a+a;
    mult2=b+b;

    while(mult1!=mult2){

        mult1=mult1+a;
        mult2=mult2+b;

    }

    printf ("%d",mult1);












    return 0;
}
