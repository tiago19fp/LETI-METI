#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int j=0;
    int matriz[2][2]={1,2,3,4};
    int numero=1;
    int soma=0;

    for(i=0;i<2;i++){

            for(j=0;j<2;j++);{

                soma= soma+matriz[i][j];

            }


    }

    printf("%d\n", soma);


    for(i=0;i<2;i++){

            for(j=0;j<2;j++)
            {

                printf("%d ", matriz[i][j]);

            }
        printf("\n");
    }


    return 0;
}
