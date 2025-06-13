#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>  // For wait()

// Signal handler for SIGCHLD (called when child terminates)
void my_isr(int n) {
    printf("In ISR (Child terminated)...\n");

    // Reap the terminated child to avoid zombie process
    //wait(0);  // Waits for any child process to change state
}

int main() {
    // Create a new child process
    if (fork() == 0) {
        // Child process
        printf("In child process\n");

        sleep(5);  // Simulate some work
        printf("Child finished sleeping, exiting...\n");

    } else {
        // Parent process

        // Register signal handler for SIGCHLD (child termination)
        signal(SIGCHLD, my_isr);

        printf("In parent process, waiting for child to terminate...\n");

        // Infinite loop to keep the parent running
        while (1);
    }

    return 0;
}
