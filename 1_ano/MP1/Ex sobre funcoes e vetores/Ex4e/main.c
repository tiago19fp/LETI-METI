#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i=0;
    int a;
    int vet[5];
    int cont;

    srand(time(NULL));
while(a){
    for(i=0;i<5;i++){

        vet[i]= 1+rand()%5;

    }

    if(vet[1]==vet[2] && vet[2]==vet[3] && vet[4]==vet[5] )  {

        break;

    }


}

for(i=0;i<5;i++){

    printf("%d\n", vet[i]);

}



}
