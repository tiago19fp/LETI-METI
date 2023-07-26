#include <stdio.h>
#include <stdlib.h>

int main()
{

   int matriz1[2][2]={{1,2},
                                           {3,4},};
    int matriz2[2][2]={{5,6},
                                            {7,8},};

   int i=0;
   int j=0;
   int soma[2][2];


   for(i=0;i<2;i++){

            for(j=0;j<2;j++){

                soma[i][j] =matriz1[i][j]+matriz2[i][j];
                printf("%d ", soma[i][j]);

                }
                printf("\n");
   }


    return 0;
}
