#include <stdio.h>
#include <signal.h>

// Signal handler function
void my_isr(int n) {
    static int c = 0, c1 = 0;  // Static counters to keep track of signals

    if (n == SIGINT) {  // If signal is SIGINT (Ctrl+C)
        c++;            // Increment SIGINT counter
        printf("Caught SIGINT (%d times)\n", c);

        if (c == 3) {
            // Restore default SIGINT behavior after 3 presses
            signal(SIGINT, SIG_DFL);
            printf("SIGINT default behavior restored.\n");
        }
    }

    if (n == SIGQUIT) {  // If signal is SIGQUIT (Ctrl+\)
        c1++;            // Increment SIGQUIT counter
        printf("Caught SIGQUIT (%d times)\n", c1);

        if (c1 == 1) {
            // Restore default SIGQUIT behavior after 1 press
            signal(SIGQUIT, SIG_DFL);
            printf("SIGQUIT default behavior restored.\n");
        }
    }
}

int main() {
    // Register custom signal handler for SIGINT (Ctrl+C) and SIGQUIT (Ctrl+\)
    signal(SIGINT, my_isr);
    signal(SIGQUIT, my_isr);

    // Infinite loop to keep program running
    while (1);

    return 0;
}

/*
1. Graceful Shutdowns (e.g., SIGINT Handling)
Scenario: A server or daemon needs to clean up resources before exiting.
    Application:
            Instead of exiting immediately on Ctrl+C, the program intercepts the signal to:
            Close open files
            Release memory
            Notify other services
            Log shutdown reason
        
            Example:
                   signal(SIGINT, handle_shutdown);


2. Temporary Protection from User Interruptions
Your Code Use Case:
    // Ignore SIGINT and SIGQUIT initially
    // Then allow them after a certain condition (e.g., after alarm or count)

    Real Use:
            During critical operations (e.g., database update, flash firmware write), you might want to disable user interrupts.
            After the critical section, signals are re-enabled to allow safe exit.

3. Rate-Limiting or Debouncing User Input
Your Counter Code:
                    if (c == 3) signal(SIGINT, SIG_DFL);
Real Use:
        Require the user to press Ctrl+C multiple times before quitting:
        Prevents accidental exits
        Used in CLI tools (e.g., Git, Vim sometimes handles interrupts carefully)

4. Soft Exit with Escalation
        Your SIGINT 3 times logic:
Real Use:
        First Ctrl+C: Show warning.
        Second: Ask for confirmation.
        Third: Exit forcefully.
    Used in tools like:
        top
        htop
        Command-line tools with long-running processes

5. Automatic Timeouts (Using alarm() + SIGALRM)
Your Code Use Case:
        alarm(10); // Timeout after 10 seconds
    Real Use:
        Auto-terminate if no input received within X seconds
    Used in:
        Login screens (auto logout on idle)
        Network services waiting for response
        Security/lock screens

6. Security: Disable Abort (Ctrl+\)
        Programs that run in public terminals or embedded devices may disable Ctrl+\ (SIGQUIT) to avoid exposing core dumps or debugging behavior.

7. Child Process Management in Daemons
        Signals like SIGCHLD, SIGTERM, and SIGINT are managed similarly to:
        Monitor when child processes finish
        Handle termination signals in a parent process or supervisor daemon

🔐 Summary: Where This Code Is Used
===================================================================================================
Application Type	                        Use of Your Code Concepts
--------------------------------------------------------------------------------------------------
Linux services / daemons	                Graceful shutdown, restart, cleanup
Command-line tools	                        Interruption control, safe exit
Embedded systems	                        Disable signal-based exits, watchdog
Security applications	                    Ignore dangerous signals temporarily
Servers	                                    Timeout requests (using alarm())









*/
