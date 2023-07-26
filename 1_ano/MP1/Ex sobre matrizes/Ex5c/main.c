#include <stdio.h>
#include <stdlib.h>
int main()
{

       int i=0;
       int j=0;
       int coluna=0;
       int med=0;
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

   printf("Qual coluna:\n");
   scanf("%d", &coluna);

    coluna= coluna-1;

   for(i=0; i<a;i++){

        med= matriz[i][coluna]+med;

   }

    med= med/a;

    printf("media:%d\n", med);

    for(i=0; i<a;i++){

            for(j=0;j<b;j++ ){

                printf("%d ", matriz[i][j]);

            }
            printf("\n");
   }

}
