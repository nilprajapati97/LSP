#include <stdio.h>
#include <unistd.h>  // Needed for alarm()

int main() {
    printf("hello.\n");

    // Set an alarm to send SIGALRM after 5 seconds
    alarm(5);

    printf("hai...\n");

    // Infinite loop to keep the program running until 5 sec
    while (1);    //comment and check

    return 0;
}

/*
Notes:
#include <unistd.h> is required for the alarm() function.

int main() is the standard declaration of the main function in C.

while(1); is a busy loop — the program will stay alive indefinitely unless interrupted.

If you want to handle the SIGALRM signal, you can install a signal handler using signal(SIGALRM, handler_function);.


*/

/*
📌 Summary
==============================================================================
Use Case	                    Why Use alarm()?
-----------------------------------------------------------------------------
Timeout on input/IO	            Prevent hangs
Periodic operations	            Simple timed tasks
Embedded systems	            Watchdog to detect hangs
Script utilities	            Enforce execution limits
Signal testing/debugging	    Simulate time-based events


*/
