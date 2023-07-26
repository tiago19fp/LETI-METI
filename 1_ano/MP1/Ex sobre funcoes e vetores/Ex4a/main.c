#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vet[6];
    int i=0;

    for(i=0;i<6;i++){

        vet[i]=1+rand()%51;

    }
       for(i=0;i<6;i++){

        printf("%d\n", vet[i]);

    }


    return 0;
}
