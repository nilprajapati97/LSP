003_LSP_ ProcessTime
-----------------------------------

Process -: A program is in Execution
Pid  -: Process id

how we will get Pid

003_LSP
-----------------------------------

Process -: A program is in Execution called process
Pid   -: Process id

NAME
       getpid, getppid - get process identification

SYNOPSIS
       #include <sys/types.h>
       #include <unistd.h>

       pid_t getpid(void);
       pid_t getppid(void);
	   
	    
	   getpid()  returns  the  process ID (PID) of the calling process
	   getppid() returns the process ID of the parent of the calling process
	   
	   Terminated - Process -:  ppid -: 1 -: Init in ppid
	   
	   #define pid_t    unsigned short integer
	   
	   pid_t  getpid(void);
	   pid_t  getppid(void);
	   
	   Ex-1 
	   
	   #include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{


		printf("Pid=%d ppid=%d\n",getpid(),getppid());

return 0;

}


output -:

Pid=2124 ppid=6431

note-: if you load the same program in RAM for the execution again same "pid" id
	not giving diffrent but "ppid" is same

Pid -:

    -: Max range 32767 (16 bit number)
	
     -: After full all process it will start with process id 300 not 00

    -: upto 300 system process and deamon process
	
	   0000 0000 min 
	   1111 1111 max
	   0000 0000

    -:process id of init is 1
    -:process id of "schedular" is 0
	
    ps 
	
	 ps -l    -: long list process in current terminal

              anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/003_LSP$ ps -l
			F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
			4 R  1001  7267  7575  0  80   0 -  7222 -      pts/3    00:00:00 ps
			0 S  1001  7575  6421  0  80   0 -  5711 wait   pts/3    00:00:00 bash

	 ps -e    -: long list process throught system
		
         ps -el   -:long list process throught system in current terminal
	 
	 
	 
	 
	 
	 process time
	  
	  1.Response time
	  2.starvation time
	  3.Turnaround time
	  4.Throughput time
	  
	  
	  States of Process -: Pending from my side
	  
         1. Ready state
         2. Delay state
         3. Wait state
         4. suspend state
	  
	  
wait state -:
              scanf("%d",&ch);

ready state
            after scanf it is in ready state
Delay state

	anil@INDCP13YY2-L:~/Desktop/Class/Linux/LSP/004_LSP$ cat 002_Delay_state.c 
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{


              
                int ch;

		printf("Pid=%d ppid=%d\n",getpid(),getppid());
	        sleep(10);

      		printf("after sleep\n");
		while(1);

return 0;


}



Random Number Generation













            













	
	
	
	
	
	
 







	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   


