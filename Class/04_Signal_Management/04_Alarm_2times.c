#include <stdio.h>
main()
{
    printf("hello.\n");
    alarm(10);
    alarm(2);
    printf("hai...\n");
    while (1);
}


// its will take latest seed fo alarm so after 2 second it will terminate . Because default action is terminate process
