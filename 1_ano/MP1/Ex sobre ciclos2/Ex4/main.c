#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int i=0;
    int max=0;


    srand(time(NULL));




    while(a==b && a==c){


                a= 1+rand()% 4;
                b= 1+rand()% 4;
                c= 1+rand()% 4;


    }











    printf("%d %d %d %d\n %d",a,b,c,d,max);

    return 0;
}
