#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function
void my_isr(int signum) {
    printf("In ISR... Signal number: %d\n", signum);
    alarm(2);
    printf("Exit from ISR\n");
}

int main() {
    // Register signal handler for SIGALRM (signal number 14)
    signal(SIGALRM, my_isr);

    printf("hello...................\n");

    // Set an alarm to go off after 5 seconds
    alarm(10);

    printf("hai....................\n");


    // Infinite loop to keep the program running
    while (1);

    return 0;
}


/*
🔁 What Happens During Execution
Program starts, prints "hello" and "hai".

After 10 seconds, SIGALRM is sent.

my_isr() runs:

Prints signal info.

Starts a new 2-second alarm (alarm(2)).

Every 2 seconds, my_isr() runs again — creating a repeating signal.

🔄 This creates an infinite loop of signals every 2 seconds after the first 10-second delay.


📌 Real-World Use Cases
✅ 1. Watchdog Timer
A watchdog ensures a process or system doesn’t hang:

If a task doesn’t finish in time, the alarm triggers.

Can be used to restart or exit stalled processes.

✅ 2. Timeouts for I/O Operations
        Used when reading from a socket, device, or user input:

        If no data comes within X seconds, abort or retry.

        alarm(5); // wait max 5 seconds
        read(fd, buffer, size); // if it blocks, SIGALRM can interrupt it


✅ 3. Periodic Polling or Status Reporting
        Some background processes use signals to:

        Log memory usage every few seconds.

        Send heartbeat messages.

        Update UI, sensors, etc.

✅ 4. Auto-Exit or Cleanup After Time
        A temporary service or debug tool may:

        Exit after 1 minute if no user activity is detected.

        Save data or perform cleanup in my_isr() before exiting.

✅ 5. Simple Scheduler
        Can act like a primitive scheduler to call different functions every few seconds in a simple single-threaded program.

⚠️ Caveats and Limitations
        signal() is simple but not robust for production — use sigaction() for more control.

        alarm() only allows one active timer per process — use setitimer() or POSIX timers for more flexibility.

        Using signals for timing is not real-time accurate — it's good for general scheduling, but not high precision.
*/