// The alarm() function in C returns a specific value that tells you about the previous alarm, if any.

#include <stdio.h>
#include <unistd.h>     // for getpid() and alarm()
#include <signal.h>     // for signal handling
#include <sys/types.h>  // optional, included for types like pid_t

// Signal handler function
void my_isr(int n) {
    printf("In ISR... Signal number: %d\n", n);
    
    // Reset signal handling to default for the next time
    signal(n, SIG_DFL);
}

int main() {
    printf("Hello world... PID = %d\n", getpid());

    // Register signal handler for SIGALRM
    signal(SIGALRM, my_isr);

    // Schedule SIGALRM to be delivered after 10 seconds
    alarm(10);

    printf("Hi...\n");

    // Infinite loop to keep the process running
    while (1);

    return 0;
}

/*
🎯 Where This Pattern Is Used in Practice
1. One-Time Custom Cleanup or Logging Before Termination
    In some system monitoring or automation scripts, you may want to:
    Log something when a timeout occurs.
    Do a one-time cleanup before shutting down.
    Print diagnostic info before a forced exit.

            void handler(int sig) {
                log_status();
                signal(sig, SIG_DFL);  // next time terminate normally
            }
✅ Practical Example:
    A daemon that has a timeout (e.g., no activity for 10 minutes), logs the session data when the alarm fires once, then allows itself to be terminated the next time.

    2. Controlled Auto-Termination With Graceful Warning
    This pattern allows you to:

    Warn the user or process that it will exit soon.

    On the second signal, it exits.

✅ Real-world Analogy:
    Like a user being warned:

    "You will be logged out in 2 minutes."
    Then if it happens again, the system logs them out.

    This could be implemented like this:
            void alarm_handler(int sig) {
                static int warned = 0;
                if (!warned) {
                    printf("Warning: About to terminate!\n");
                    warned = 1;
                    alarm(5); // give 5 more seconds
                } else {
                    signal(sig, SIG_DFL); // next time, die
                }
            }
3. Watchdog/Timeout in Embedded Systems
    In embedded Linux, SIGALRM is used to simulate a watchdog timer:
    If the process doesn’t respond or reset the timer, it gets killed.
    On the first timeout, maybe log or reset a component.
    On the second, reboot or crash safely.

4. Timeout Testing in Debugging
    This code pattern is useful in test harnesses:
    You run code that's supposed to finish within X seconds.
    If it hangs, you catch that with a signal.
    On second hang, abort the test.

⚠️ Limitations in Production Use
    -: While this kind of signal handling is fine for learning and simple scripts, in real production code, you'd likely use:
    -: sigaction() instead of signal() for better control.
    -: setitimer() or timer_create() for multiple or more precise timers.
    -: A dedicated watchdog thread or external watchdog service in complex systems.

🧠 TL;DR — Practical Uses of Your Code Pattern
============================================================
Use Case	                            Why This Code Helps
------------------------------------------------------------
Graceful warning before shutdown	    Alert user/process once before auto-termination
Logging or cleanup before crash	        ISR logs or cleans up before second signal kills
Embedded watchdog timer	                Force exit or restart after timeout
Debugging / timeout-based testing	    Identify hangs or deadlocks
Simple scheduling in CLI tools	        Perform delayed operations


*/
