#include <stdio.h>      // For printf()
#include <unistd.h>     // For alarm(), sleep()
#include <signal.h>     // For signal handling (signal(), SIGINT, etc.)

// Custom signal handler function for SIGALRM
void my_isr(int n) {
    printf("in isr...\n");

    // Restore default signal handling for SIGINT (Ctrl+C) and SIGQUIT (Ctrl+\)
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}

int main() {
    // Ignore SIGINT (Ctrl+C) — user can't interrupt with Ctrl+C
    signal(SIGINT, SIG_IGN);

    // Ignore SIGQUIT (Ctrl+\) — user can't interrupt with Ctrl+\
    signal(SIGQUIT, SIG_IGN);

    // Register custom handler (my_isr) for SIGALRM
    signal(SIGALRM, my_isr);

    // Set an alarm to go off in 10 seconds (sends SIGALRM)
    alarm(10);

    // Infinite loop to keep the program running
    while (1);

    return 0;  // This line is never reached due to infinite loop
}
