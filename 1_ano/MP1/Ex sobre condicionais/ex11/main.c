#include <stdio.h>
#include <stdlib.h>

int main()
{
    char EstCivil = ' ';

    printf("Escreva o seu estado civil:\n" );
    scanf("%c",&EstCivil);

    if(EstCivil == 'C'){

        printf("Casado.");

    }else if(EstCivil == 'S'){

        printf("Solteiro.");

    }if(EstCivil == 'D'){

        printf("Divorciado.");

    }

    return 0;
}
