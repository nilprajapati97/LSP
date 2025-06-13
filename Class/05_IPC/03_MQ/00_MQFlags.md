🏁 Message Flags (msgflg)
====================================================================
1. 🕒 IPC_NOWAIT
    Meaning: Do not block if the message is not available.
    Usage: If the message of the specified type isn’t available, msgrcv() returns -1 immediately and sets errno to ENOMSG.

    ✅ Use case: Non-blocking receive.
        msgrcv(msqid, &msg, sizeof(msg.data), 1, IPC_NOWAIT);

2. 🎯 MSG_EXCEPT
    Meaning: Receive any message that does not match the msgtyp argument.
    Usage: Works only if msgtyp is greater than 0.
    Returns the first message whose mtype != msgtyp.

    ✅ Use case: Skip a certain message type.
        msgrcv(msqid, &msg, sizeof(msg.data), 2, MSG_EXCEPT);

3. ✂️ MSG_NOERROR
    Meaning: Truncates message if it’s longer than msgsz instead of failing.
    Usage: Prevents E2BIG error when the message content is larger than the provided buffer.
    
    ✅ Use case: Safer in size-limited buffers, avoids failure.
        msgrcv(msqid, &msg, 10, 1, MSG_NOERROR);  // truncates if > 10 bytes

🧠 You Can Combine Flags:
    Use | (bitwise OR) to combine flags.
        msgrcv(msqid, &msg, sizeof(msg.data), 2, IPC_NOWAIT | MSG_EXCEPT);
    
    🧪 Example Usage
        int ret = msgrcv(msqid, &msg, sizeof(msg.data), 3, IPC_NOWAIT | MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv failed");
        }
