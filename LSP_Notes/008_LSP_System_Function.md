008_LSP_System Function
*******************************



System Function -: execute shell commands

NAME
       system - execute a shell command

SYNOPSIS
       #include <stdlib.h>

       int system(const char *command); // ls, pwd

DESCRIPTION
       The  system()  library  function uses fork(2) to create a child process that executes the shell command specified in command using execl(3) as
       follows:

           execl("/bin/sh", "sh", "-c", command, (char *) 0);

       system() returns after the command has been completed.

       During execution of the command, SIGCHLD will be blocked, and SIGINT and SIGQUIT will be ignored, in the process that  calls  system()  (these
       signals will be handled according to their defaults inside the child process that executes command).

       If command is NULL, then system() returns a status indicating whether a shell is available on the system.

RETURN VALUE
       The return value of system() is one of the following:

       *  If command is NULL, then a nonzero value if a shell is available, or 0 if no shell is available.

       *  If a child process could not be created, or its status could not be retrieved, the return value is -1.

       *  If  a  shell  could not be executed in the child process, then the return value is as though the child shell terminated by calling _exit(2)
          with the status 127.

       *  If all system calls succeed, then the return value is the termination status of the child shell used to execute command.  (The  termination
          status of a shell is the termination status of the last command it executes.)



#include <stdlib.h>
int main()
{


		printf("Hello....\n");
		//system("ls");
		system("cal");
		printf("Hai...\n");
		while(1);

		return 0;


}
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ cal
     June 2021        
Su Mo Tu We Th Fr Sa  
       1  2  3  4  5  
 6  7  8  9 10 11 12  
13 14 15 16 17 18 19  
20 21 22 23 24 25 26  
27 28 29 30           
                      
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ./a.out
Hello....
     June 2021        
Su Mo Tu We Th Fr Sa  
       1  2  3  4  5  
 6  7  8  9 10 11 12  
13 14 15 16 17 18 19  
20 21 22 23 24 25 26  
27 28 29 30           
                      
Hai...
^C

Ex-2 -:
*******************

anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ cat 0002_System.c
#include <stdio.h>
#include <stdlib.h>
int main()
{


		printf("Hello.... Pid=%d\n",getpid());
		//system("ls");
		system("cal");
		printf("Hai...\n");
                while(1);
		return 0;


}
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ cat 0003_System.c 
#include <stdio.h>
#include <stdlib.h>
int main()
{


		printf("Hello..ANIL.. Pid=%d\n",getpid());
		//system("ls");
		system("./p2");
		printf("Hai...\n");
               // while(1);
		return 0;


}


output -: 

anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 poll_s pts/7    00:00:00 bash
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 wait   pts/7    00:00:00 bash
0 R  1001  5552  5060 99  80   0 -  1128 -      pts/7    00:00:07 a.out
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 wait   pts/7    00:00:00 bash
0 R  1001  5905  5060 96  80   0 -  1128 -      pts/7    00:00:03 p2
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 wait   pts/7    00:00:00 bash
0 S  1001  6106  5060  0  80   0 -  1128 wait   pts/7    00:00:00 a.out
0 S  1001  6107  6106  0  80   0 -  1158 wait   pts/7    00:00:00 sh
0 R  1001  6108  6107 99  80   0 -  1128 -      pts/7    00:00:33 p2
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 wait   pts/7    00:00:00 bash
0 S  1001  6106  5060  0  80   0 -  1128 wait   pts/7    00:00:00 a.out
0 S  1001  6107  6106  0  80   0 -  1158 wait   pts/7    00:00:00 sh
0 R  1001  6108  6107 99  80   0 -  1128 -      pts/7    00:03:37 p2
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ 

CTRL +C  in running Terminal

anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 wait   pts/7    00:00:00 bash
0 S  1001  6106  5060  0  80   0 -  1128 wait   pts/7    00:00:00 a.out
0 S  1001  6107  6106  0  80   0 -  1158 wait   pts/7    00:00:00 sh
0 R  1001  6108  6107 99  80   0 -  1128 -      pts/7    00:03:37 p2

CTRL +C  in running Terminal  (running ./a.out binary running terminal)
  
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ ps -el | grep pts/7
0 S  1001  5060 23154  0  80   0 -  5711 poll_s pts/7    00:00:00 bash
anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/008_LSP$ 













              
