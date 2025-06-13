006_LSP_Process Controll Block
*******************************

information -: ./a.out
**********************************
1.Binary format identifiction
2.maschine language instruction
3.program entry point
4.Data
5.sysmbol and relocation table
6 shared library && dymanic library linking information


Suppose these above filed copy into some block. -: PCB

PCB -: Process Control Block

1.Program Code
2.Variable used by that code
      1.uninitialize data
      2.initialize data

3.PID
4.Virtual Memory
5.Signal Deliever and handling
6 Process  resource usage and limits,pwd information

Ex-:
 process 1 //parent

{

    process 2  // child
    {
    
    }


}
note-: if child process become orpthan becuse its "birth" parent terminate than it is adopted by "init process"



** Non local goto **

1. setjmp() = setting labels
2. long jmp() = calling lables


Note -: Local goto use for forward and backward jmp possible


Forwardword

-----
    calling
-----
   defining
---

Ex-1 -Forward jmp

main()
{


 calling label  


}
void my_function(int , int)
{


label:  // label defination
       statement:
       statement2:
 
}


Ex- 2 Backword jmp


main()
{


label: // Lebel defination   


}
void my_function(int , int)
{


:
       statement:
        call label;
       statement2:
}

Intro -:

NAME
       setjmp, sigsetjmp, longjmp, siglongjmp  - performing a nonlocal goto

SYNOPSIS
       #include <setjmp.h>

       int setjmp(jmp_buf env);
       int sigsetjmp(sigjmp_buf env, int savesigs);

       void longjmp(jmp_buf env, int val);
       void siglongjmp(sigjmp_buf env, int val);





EX-1


#include<stdio.h>
void print(void); // declaration
#include <setjmp.h>
jmp_buf v;
int main()
{

	printf("Hello.......\n");
	setjmp(v); // setting a label

	printf("Hail......\n");
	print();

return 0;


}
void print(void)
{
	printf("In print function....\n");
	longjmp(v,1); // calling label

	printf("in print after long jmp...\n");


}

Output -:
In print function....
Hail......
In print function....
Hail......
In print function....
Hail......
In print function....
Hail......
In print function....
Hail......
In print function....
Hail......
In print function....

Ex-2

#include<stdio.h>
void print(void); // declaration
#include <setjmp.h>
jmp_buf v;
int main()
{

	printf("Hello.......\n");
	setjmp(v);

	printf("Hail......\n");
	print();

return 0;


}
void print(void)
{
	printf("In print function....\n");
	longjmp(v,1);

	printf("in print after long jmp...\n");


}

output -:



Hello.......
In main function.....
Hail......
In print function....
In main function.....
Hail......
In print function....
In main function.....
Hail......
In print function....



Note -: stack hold function return address so 8MB stack is filled with address.
     -: using setjmp and longjmp stack is fully filled

output -: not getting segmentation fault


Details -:
        -: setjmp os creat a stack upto longjmp()
        -: longjmp roll the stack upto setjmp
      
        -: setjmp() Usefull for dealing with handling error , interrupts executed in a LOW-Level subroutine of a program.
        -:setjmp saves the stack context / environement and later is used by longjmp
        -:setjmp return a 0.

       -:jmp_buf is internally as a one structure and same member consists in the structure



Ex2 -:


#include<stdio.h>
#include<setjmp.h>
int sum(int ,int);
int sub (int ,int);
int mul(int ,int );
int dive(int ,int );
jmp_buf v;
main()
{
	int n1,n2,n3,op,r;

	printf("hello...\n");

	r=setjmp(v);

	if(r==3)
		printf("error in mul...\n");
	else if(r==4)
		printf("error in dive...\n");


	printf("enter the number...\n");
	scanf("%d%d",&n1,&n2);
	printf("enter the option...\n");
	scanf("%d",&op);

	if(op==1)
	{
		n3=sum(n1,n2);
		printf("n3=%d\n",n3);
	}

	else if(op==2)
	{
		n3=sub(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if(op==3)
	{
		n3=mul(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if(op==4)
	{
		n3=dive(n1,n2);
		printf("n3=%d\n",n3);
	}
	else 
		printf("invalid option...\n");



}
int sum(int i,int j)
{

	return i+j;

}
int sub(int i,int j)
{
	return i-j;

}
int mul(int i, int j)
{
	if(i==0 || j== 0)
		longjmp(v,3);

	return(i*j);

}
int dive(int i,int j)
{
	if(i==0 || j==0)
		longjmp(v,4);

	return(i/j);

}

 













































































































