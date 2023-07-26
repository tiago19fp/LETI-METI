#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int i=0;
    int j=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int cont=0;
    int mul=0;
    int soma=0;
    int numero=1;
    scanf("%d %d", &a, &b);

    int matriz[a][b];
    int matriz2[a][b];

    mul=a*b;

    for(i=0;i<a;i++){

            for(j=0;j<b;j++){

                printf("Elemento[%d][%d]:", i+1,j+1);
                scanf("%d", &matriz[i][j]);

            }

    }




            for(i=0,c=a-1;i<a;i++,c--){

                    for(j=0, d=b-1;j<b;j++, d--){

                        if(matriz[i][j] == matriz[c][d]){

                            cont++;

                        }

                    }



            }

  if(cont== mul){

    printf("Simetrica\n");


  }else{

    printf("Nao simetrica\n");

  }

for(i=0;i<a;i++){

        for(j=0;j<b;j++){

            printf("%d  ", matriz[i][j]);


        }
    printf("\n");
}

    printf("soma=%d", soma);


    return 0;
}
