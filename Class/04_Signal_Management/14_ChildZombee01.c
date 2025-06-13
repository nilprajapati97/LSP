#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>  // For wait()

// Signal handler for SIGCHLD
void my_isr(int n) {
    printf("In ISR (SIGCHLD received) — child terminated.\n");

    // Reap the terminated child to avoid zombie process
    //wait(0);    // comment for deamon process and become zombie
}

int main() {
    if (fork() == 0) {
        // Child process
        printf("In child process\n");

        sleep(5);  // Simulate some work
        printf("Child finished sleeping, exiting...\n");

    } else {
        // Parent process
        signal(SIGCHLD, my_isr);  // Register SIGCHLD handler

        printf("In parent process. Waiting for child to finish...\n");

        // Infinite loop, printing something every 2 seconds
        while (1) {
            printf("Parent running... (main loop)\n");
            sleep(2);  // Delay to make output readable
        }
    }

    return 0;
}
