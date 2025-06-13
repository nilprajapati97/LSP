#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int ret;

    printf("Hello...\n");

    ret = alarm(10);               // Step 1: Set alarm for 10 seconds
    printf("ret = %d\n", ret);     // Step 2: Print return value (expected 0)

    printf("Hai....\n");

    ret = alarm(3);                // Step 3: Set new alarm for 3 seconds
    printf("ret = %d\n", ret);     // Step 4: Print return value (expected ~10)

    while (1);                     // Step 5: Infinite loop to keep program alive

    return 0;
}

/*
🖨️ Expected Output
    Hello...
    ret = 0
    Hai....
    ret = 10



📖 Explanation (Line by Line)
        printf("Hello...\n");
        
        Simply prints "Hello..."
        
        alarm(10);
        
        Sets an alarm to go off in 10 seconds.
        
        No alarm was previously set, so it returns 0.
        
        printf("ret = %d\n", ret);
        
        Prints the return value from the previous alarm() call: ret = 0.
        
        printf("Hai....\n");
        
        Prints "Hai...."
        
        alarm(3);
        
        Sets a new alarm to go off in 3 seconds.
        
        Cancels the previous 10-second alarm.
        
        Returns the number of seconds left on the old alarm, which is approximately 10 because almost no time has passed since setting it.
        
        printf("ret = %d\n", ret);
        
        Prints ret = 10.
        
        while (1);
        
        Keeps the program running forever to allow the alarm (SIGALRM) to trigger.
        
        But: You did not define a signal handler (my_isr) and did not call signal(SIGALRM, handler).

⚠️ What Happens After 3 Seconds?
        The program receives SIGALRM after 3 seconds.

        Since no handler is installed, the default action for SIGALRM is to terminate the process.

        So your program will exit after 3 seconds, even though the while(1) loop would otherwise run forever.

🔄 Actual Behavior Summary:
===============================================================================+++++++++++============
Line	        What Happens	                                    Why it Happens
------------------------------------------------------------------------------------------------------
alarm(10)	    Sets timer for 10 seconds	                        No previous alarm, so returns 0
alarm(3)	    Cancels 10s alarm, sets new 3s one	                Returns remaining time of old alarm (10)
After 3s	    Program exits	                                    Default action for SIGALRM is terminate

Let me know if you want to handle the signal instead of terminating, or log a message when the alarm triggers.

*/
