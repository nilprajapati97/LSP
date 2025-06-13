#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

pthread_mutex_t m1,m2;

void *thread_1(void *p)
{
    char i;
    for(i='a' ;i< 'z';i++)
    {
        pthread_mutex_lock(&m1);
        printf("%c\t",i);
        fflush(stdout);
        sleep(1);
        pthread_mutex_unlock(&m2);
    }
}

void *thread_2(void *p)
{
    char i;
    for(i='A' ;i< 'Z';i++)
    {
        pthread_mutex_lock(&m2);
        printf("%c\n",i);
        sleep(1);
        pthread_mutex_unlock(&m1);
    }
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&m1,NULL);
    pthread_mutex_init(&m2,NULL);
    pthread_mutex_lock(&m2);

    // Create reader thread
    if (pthread_create(&t1, NULL, thread_1, NULL) != 0)
    {
        perror("pthread_create thread 1");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&t2, NULL, thread_2, NULL) != 0)
    {
        perror("pthread_create thread 2");
        exit(EXIT_FAILURE);
    }
   
    pthread_exit(0);

    return 0;
}
/*
output
===================

a	A
b	B
c	C
d	D
e	E
f	F
g	G
h	H
i	I
j	J
k	K
l	L
m	M
n	N
o	O
p	P
q	Q
r	R
s	S
t	T
u	U
v	V
w	W
x	X
y	Y
z   Z

*/