#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n=0;
    int num=0;
    int numAn=0;
    int numAn2=0;
    int i=0;

    srand(time(0));

    scanf("%d",&n);

    for(i=0;i<n;i++){
            num= rand()%100;

            if(num==numAn || num==numAn2){

                while(num==numAn || num==numAn2){

                            num= rand()%100;

                }

            }else{


            printf("%d\n",num );


            }

            numAn=num;
            numAn2=numAn;

    }

    getch();
    return 0;
}
