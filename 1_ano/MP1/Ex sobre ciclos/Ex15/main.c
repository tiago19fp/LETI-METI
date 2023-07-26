#include <stdio.h>
#include <stdlib.h>

int main(){
        int resto=0;
        int num1=0;
        int num2=0;

        printf("Escreva dois numeros:\n");
        scanf("%d %d",&num1, &num2);


        resto= num1%num2;

        while(resto!=0){

            num1=num2;
            num2=resto;
            resto=num1%num2;

        }


        printf("%d",num2);


        return 0;

}
