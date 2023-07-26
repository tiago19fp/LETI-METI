#include <stdio.h>
#include <stdlib.h>


int maior(n1,n2,n3,n4,n5){

      int i=0;
      int m=5;
      int max;

      if(n1>n2  && n1>n3 && n1>n4 && n1>n5){

     return n1;

      }
      if(n2>n1&& n2>n3 && n2>n4 && n2>n5 ){

    return n2;

      }
      if(n3>n1&& n3>n2 && n3>n4 && n3>n5 ){

     return n3 ;

      }
      if(n4>n1&& n4>n2 && n4>n3 && n4>n5 ){

     return n4;

      }
      if(n5>n1&& n5>n2 && n5>n3 && n5>n4 ){

    return n5;

      }

}

int menor(n1,n2,n3,n4,n5){

 int i=0;
      int m=5;
      int min;

      if(n1<n2  && n1<n3 && n1<n4 && n1<n5){

     return n1;

      }
      if(n2<n1&& n2<n3 && n2<n4 && n2<n5 ){

     return n2 ;

      }
      if(n3<n1&& n3<n2 && n3<n4 && n3<n5 ){

     return n3 ;

      }
      if(n4<n1&& n4<n2 && n4<n3 && n4<n5 ){

     return n4 ;

      }
      if(n5<n1&& n5<n2 && n5<n3 && n5<n4 ){

     return n5;

      }

}

int media(max,min, media){

    media= (max+min)/2;

    return media;


}

int main()
{
    int n1,n2,n3,n4,n5;
    int max;
    int min;
    int med;

    printf("Escreva 5 numeros:");

    scanf("%d %d %d %d %d", &n1,&n2,&n3,&n4,&n5);

    max= maior(n1,n2,n3,n4,n5);
    min= menor(n1,n2,n3,n4,n5);
    med=media(max,min, media);


    printf("Maior:%d  Menor:%d  Media:%d",max,min,med);

    getch();
    return 0;
}
