#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    srand(time(0));

    printf(" Face: %d\n", rand()%6+1);

    getch();
    return 0;
}
