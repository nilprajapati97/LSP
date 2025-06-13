✅ Shared vs Unique Data Between Threads in Linux
==============================================================
✅ Shared Data (Accessible by all threads in the same process)
---------------------------------------------------------------------------
Shared Resource	                        Description
---------------------------------------------------------------------------
Heap memory (malloc/new)	            All threads share heap space.
Global variables / static vars	        Accessible and modifiable by all threads.
File descriptors	                    Shared; changes affect all threads (e.g., close()).
Process-wide open files	                Threads can read/write same files.
Memory-mapped files (mmap)	            Shared if mapped as MAP_SHARED.
Signal dispositions	                    Shared unless explicitly blocked per thread.
Process ID (PID)	                    All threads share the same PID, but have unique TIDs.
User ID, group ID	                    Same for all threads.
Address space	                        Fully shared.
Environment variables	                Shared (not thread-safe if modified).
Working directory	                    Shared (changing chdir() affects all).
Stack of other threads	                Can be accessed via pointer, but not recommended.
Shared libraries / code segment	        Same loaded code, shared between all threads.

🚫 Unique Data (Private per thread)
=======================================================================================
Unique Resource	                   Description
----------------------------------------------------------------------------------------
Stack memory	                   Each thread has its own stack.
Thread ID (TID)	                   Unique per thread (gettid() or pthread_self()).
errno	                           Per-thread error number (errno is thread-local).
Thread-local storage (TLS)	       Declared using __thread or thread_local.
Scheduling policy and priority	   Can be set individually via pthread_setschedparam().
Thread-specific data	           Can be set using pthread_key_create() & pthread_setspecific().
Signal mask / blocked signals	   Threads can block different signals.
Return value from pthread_exit()   Each thread returns separately.



🧠 Summary Table
===============================================================
Data / Resource	                        Shared Between Threads?
---------------------------------------------------------------
Heap	                                ✅ Yes
Global variables	                    ✅ Yes
File descriptors	                    ✅ Yes
Stack	                                ❌ No
TLS / thread_local vars	                ❌ No
errno	                                ❌ No
Signal mask	                            ❌ No
PID	                                    ✅ Yes (same for all threads)
TID	                                    ❌ No (unique per thread)

🔹 1. What is the difference between a process and a thread?
================================================================================
| Aspect         | Process              | Thread                           |
| -------------- | -------------------- | -------------------------------- |
| Memory         | Own memory space     | Shared memory with threads       |
| Context switch | Costly (full switch) | Lightweight (same address space) |
| Communication  | IPC (pipes, sockets) | Direct memory access             |
| Fault impact   | One crashes others   | Can crash whole process          |


🔹 2. What is a race condition? How do you avoid it?
================================================================================
Answer:
A race condition occurs when two threads access shared data concurrently, and at least one of them writes to it.

Avoid using:

pthread_mutex_lock()/unlock()

pthread_rwlock

std::atomic (C++)

Design-level solutions like message queues


🔹 3. What happens if one thread crashes or segfaults?
==============================================================================================
Answer:

If one thread in a process crashes (e.g., via SIGSEGV), it typically brings down the whole process, unless signal is caught or handled.

Use signal masking or a watchdog thread to handle/monitor.


🔹 4. How to cancel a thread? Is it safe?
==============================================================================================
Answer:
Use pthread_cancel(thread_id). It is asynchronous, and may interrupt execution anywhere, causing resource leaks.

Safer way:

Use cooperative cancellation:

Shared flag checked in the thread loop.

Or use pthread_setcancelstate() and cleanup handlers.

🔹 5. What are mutex vs spinlock? When to use which?
==============================================================================================
| Aspect       | `pthread_mutex`        | `spinlock` (`pthread_spinlock`)      |
| ------------ | ---------------------- | ------------------------------------ |
| Behavior     | Sleeps if locked       | Busy-waits (spins)                   |
| Suitable for | Long critical sections | Very short, low-latency sections     |
| Context      | User & kernel space    | Mostly used in kernel or RT contexts |


🔹 6. How to ensure thread safety in file I/O or data structures?
==============================================================================================
Answer:

Protect file descriptors or buffers with mutexes.

Use reentrant versions of libc functions (strtok_r, asctime_r).

In C++: use std::mutex, std::lock_guard, or thread-safe containers.

🔹 7. What is false sharing? How to avoid it?
==============================================================================================
Answer:
False sharing occurs when multiple threads access different variables that happen to reside on the same CPU cache line.

Impact: Causes unnecessary cache line invalidation → performance degradation.

Avoidance:

Padding structs or aligning variables (__attribute__((aligned(64))))

Avoid global variables used by multiple threads.