#include <stdio.h>
#include <stdlib.h>

 int main()
{
   int i=0;
   int j=0;
   int matriz[3][3];


   for(i=0; i<3;i++){

            for(j=0;j<3;j++ ){

                printf("Elemento [%d][%d]: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);

            }

   }


for(i=0; i<3;i++){

            for(j=0;j<3;j++ ){

                printf("%d ", matriz[i][j]);

            }
            printf("\n");
   }

    return 0;
}



