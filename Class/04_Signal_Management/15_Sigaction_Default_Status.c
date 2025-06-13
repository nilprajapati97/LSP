#include <stdio.h>
#include <signal.h>

int main() {
    int num;
    void (*p)(int);  // Function pointer to store previous signal handler

    // Ignore SIGINT (signal number 2, typically Ctrl+C)
    signal(2, SIG_IGN);

    // Ask user to enter a signal number
    printf("Enter the signal number: ");
    scanf("%d", &num);

    // Set the signal handler for 'num' to SIG_IGN, and save the previous handler in 'p'
    p = signal(num, SIG_IGN);

    // Restore the previous signal handler for 'num'
    signal(num, p);

    // Check what the previous signal handler was
    if (p == SIG_DFL) {
        printf("Previous handler was: default (SIG_DFL)\n");
    } else if (p == SIG_IGN) {
        printf("Previous handler was: ignore (SIG_IGN)\n");
    } else {
        printf("Previous handler was: custom handler (user-defined ISR)\n");
    }

    return 0;
}
