#include <stdio.h>
#include <stdlib.h>

int main()
{
     int soma=0;
     int num;
     int num2;
     int cont=0;

        printf("Escreva um numero:");
        scanf("%d",&num);
        soma=soma+num;

        while(cont<29){

                    printf("\nEscreva mais um numero:");
                    scanf("%d",&num2);

                    while(num2==num){

                                printf("Esreva outro numero:");
                                scanf("%d",num2);

                    }  if(num2!=num){

                    soma=soma+num2;
                    num2=num;


                    }


             cont++;

        }

    printf("soma:%d",soma);
    return 0;
}
