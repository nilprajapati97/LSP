#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    // Print the process ID for testing
    printf("PID: %d\n", getpid());

    // Ignore SIGINT (Ctrl+C) and SIGQUIT (Ctrl+\)
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);

    printf("Ctrl+C and Ctrl+\\ are disabled for 10 seconds.\n");

    // Wait for 10 seconds
    sleep(10);

    // Restore default signal handlers
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);

    printf("Ctrl+C and Ctrl+\\ are now re-enabled.\n");

    // Keep running to allow testing
    while (1) {
        printf("Running... Press Ctrl+C or Ctrl+\\ now.\n");
        sleep(2);
    }

    return 0;
}
