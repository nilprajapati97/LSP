
/*

🧠 Why Use pause();
It is mainly used in:

Signal-driven programs: To wait for signals (like SIGINT, SIGTERM, or custom ones).

Daemons or background processes: To stay idle until an event occurs.

Simple test programs: To keep them alive for testing signal handling.


*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGINT, handler); // Handle Ctrl+C
    printf("Waiting for signal...\n");
    pause();  // Wait for signal
    printf("Exiting\n");
    return 0;
}

/*
Run this and press Ctrl+C (sends SIGINT).

The signal handler runs, and then the program exits.


 Notes
If no signal handler is set, and a signal like SIGKILL or SIGSTOP is sent, pause() won’t return — the process is terminated or stopped.

For better control over multiple signals, sigsuspend() or sigwait() (POSIX) are often preferred in more complex programs.





*/