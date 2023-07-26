#include <stdio.h>
#include <stdlib.h>


int Numero( a){



    if(a>0){

        printf("\n1");

    }else{

    printf("\n-1");

    }

}

int main()
{

       int a=0;

    printf("Escreva um numero:");
    scanf("%d",&a);
    Numero(a);

    return 0;
}
