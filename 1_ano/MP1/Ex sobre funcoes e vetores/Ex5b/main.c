#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int j=0;
    int num=0;
    int vet[j];

   printf("Escreva o numero:\n");
   scanf("%d", &num);


    if(num==0){

        j=1;

    }

    while(num!=0){

        j++;
        num=num/10;

    }

    for(i=0;i<j;i++){

        vet[i]=num/10;


    }

        for(i=0;i<j;i++){

            printf("%d  ", vet[i]);

        }



    return 0;
}
