#include <stdio.h>
#include <stdlib.h>

int main()
{

       int i=0;
       int j=0;
       int linha=0;
       int min=0;
       int a=0;
       int b=0;

       printf("dimensao da matriz:");
       scanf("%d  %d", &a,&b);
       int matriz[a][b];

    for(i=0; i<a;i++){

            for(j=0;j<b;j++ ){

                printf("Elemento [%d][%d]: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);

            }

   }

   printf("Qual linha:\n");
   scanf("%d", &linha);

    linha= linha-1;
     min=matriz[linha][0];

   for(j=1; j<b;j++){

        if(min>matriz[linha][j])
{
    min = matriz[linha][j];
}

   }



    printf("Minimo:%d\n", min);

    for(i=0; i<a;i++){

            for(j=0;j<b;j++ ){

                printf("%d ", matriz[i][j]);

            }
            printf("\n");
   }

}
