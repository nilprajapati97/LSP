#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function
void my_isr(int signum) {
    printf("In ISR... Signal number: %d\n", signum);
    printf("Exit from Isr\n");
}

int main() {
    // Register signal handler for SIGALRM (signal number 14)
    signal(SIGALRM, my_isr);

    printf("hello\n");

    // Set an alarm to go off after 5 seconds
    alarm(5);

    printf("hai 0..\n");
    printf("hai 1..\n");

    // Infinite loop to keep the program running
    while (1);

    return 0;
}
