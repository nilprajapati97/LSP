#include <stdio.h>
#include <unistd.h>     // For alarm(), sleep()
#include <signal.h>     // For signal handling

// Signal handler for SIGALRM
//void my_isr(int n) {
//    printf("In ISR...\n");
//
//    // Schedule the next alarm in 3 seconds
//    alarm(3);
//}

int main() {
    int ret;

    // Register the signal handler for SIGALRM (signal number 14)
    //signal(SIGALRM, my_isr);

    printf("Hello...\n");

    // Set alarm for 15 seconds and store return value
    ret = alarm(10);
    printf("ret = %d\n", ret); // Should print 0 (no previous alarm)

    printf("Hai....\n");

    // Set new alarm for 3 seconds, get remaining time from previous alarm
    ret = alarm(3);
    printf("ret = %d\n", ret); // Should print ~12 seconds (15 - 3)

    // Infinite loop to keep the program running
    while (1);

    return 0;
}

/*
output -:

*/
