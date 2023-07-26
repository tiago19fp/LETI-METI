#include <stdio.h>
#include <stdlib.h>

int main()
{

       int i=0;
       int j=0;
       int num=0;
       int oco=0;
       int a=0;
       int b=0;

       printf("Numero:\n");
       scanf("%d", &num);

       printf("dimensao da matriz:");
       scanf("%d  %d", &a,&b);
       int matriz[a][b];

    for(i=0; i<a;i++){

            for(j=0;j<b;j++ ){

                printf("Elemento [%d][%d]: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);
                if(matriz[i][j] == num){

                            oco++;

                }
            }

   }


   printf("O numero %d aparece %d na matriz\n",num,oco);

    for(i=0; i<a;i++){

            for(j=0;j<b;j++ ){

                printf("%d ", matriz[i][j]);

            }
            printf("\n");
   }

}
