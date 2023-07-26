#include <stdio.h>
#include <stdlib.h>

char Rodaletra(char letra){

    char let=' ';
    if(letra>65 && letra<90){


        let= letra--;



    }else if(letra== 'A'){


    let= 'Z';

    }


    return let;


}




int main()
{
    char letra=' ';
    scanf("%c",&letra);
    letra=Rodaletra(letra);

    printf("%c", letra);

    return 0;
}
