003_LSP_Random_Number_Generation
-----------------------------------


synopsis-: NAME
       rand, rand_r, srand - pseudo-random number generator

SYNOPSIS
       #include <stdlib.h>

       int rand(void);

       int rand_r(unsigned int *seedp);

       void srand(unsigned int seed);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       rand_r():
           Since glibc 2.24:
               _POSIX_C_SOURCE >= 199506L
           Glibc 2.23 and earlier
               _POSIX_C_SOURCE

1.The rand() function returns a pseudo-random integer in the range 0 to RAND_MAX inclusive (i.e., the mathematical range [0, RAND_MAX]).
2.The srand() function sets its argument as the seed for a new sequence of pseudo-random integers to be returned by rand().  These sequences are
  repeatable by calling srand() with the same seed value.

srand function is usefull giving a seed to the rand fucntion so that rand() will generate another sequesnce of random number.



#define RAN_MAX 214748367 (sam as MAX_INT)

#define EXIT_SUCESS 1

#define EXIT_FAILURE 0


#include<stdio.h>
main()
{
	int a[5],i;

	printf("\n....Start-----------..Main----------.Exit--------.....");
		for(i=0;i<5;i++)
			a[i]=rand();

	for(i=0;i<5;i++)
		printf("Value=%d\n",a[i]);
	printf("\n...Main----------.Exit--------.....");


}
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

....Start-----------..Main----------.Exit--------.....Value=1804289383
Value=846930886
Value=1681692777
Value=1714636915
Value=1957747793

...Main----------.Exit--------.....anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

....Start-----------..Main----------.Exit--------.....Value=1804289383
Value=846930886
Value=1681692777
Value=1714636915
Value=1957747793

...Main----------.Exit--------.....

Note -: again and again ./a.out everytime number is same , because seed is not changed,



Ex -2 
***************************************************************


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
        int a[5],i;
     srand(time(0));
        printf("\n================Start=============\n");
                for(i=0;i<5;i++)
                        a[i]=rand();

        for(i=0;i<5;i++)
                printf("Value=%d\n",a[i]);
        printf("\n================Start=============\n");

        return 0;
}

output -:
===========

Note -:if we press within 1 second than it will give same random number otherwise different

same -:

	anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

	================Start=============
	Value=377122700
	Value=128952179
	Value=67611860
	Value=258061384
	Value=29659409

	================Start=============
	anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

	================Start=============
	Value=377122700
	Value=128952179
	Value=67611860
	Value=258061384
	Value=29659409

Note -: we pressed ./a.out after 1 second delay

	anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

	================Start=============
	Value=1370125220
	Value=1831405002
	Value=2062033394
	Value=1085482431
	Value=2052897451

	================Start=============
	anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/005_LSP$ ./a.out 

	================Start=============
	Value=758253919
	Value=1454724865
	Value=137883456
	Value=308616070
	Value=691710901

	================Start=============


+
-

















































































