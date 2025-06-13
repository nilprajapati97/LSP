#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
void my_isr(int n)
{
    printf("in isr...%d\n", n);
    signal(2,SIG_IGN);
}
int main()
{
    printf("hello world....pid=%d\n", getpid());
    signal(2,my_isr);
    
    printf("bye..\n");
    while(1);

    return 0;
}

//Ignore default action 
/*
hello world....pid=14951
bye..
^Cin isr...2
^C^C^C^C^C^C^C^C^C^C
^C^C^C^C^C^CZZ^X^Z
[1]+  Stopped                 ./a.out


*/
