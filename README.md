## Repo for Lab Week 10

Complete assignment as assigned.

Note, no make file is provided.  It is suggested you create one to be more efficient building your programs.



A Makefile has been created, please see the executable file names.



**Signal Research - Part 1**



* Signal disposition: determines how the process behaves when the signal is delivered to it.
* Signal handler: a programmer-defined function which is automatically called when the signal is delivered. It catches the signal that is delivered and processes it, including custom actions that the program will perform when this occurs.



* 5 defaults dispositions:

1. Term: the process terminates
2. Ign: the signal is ignored
3. Core: the process terminates and dumps core (core file is generated)
4. Stop: the process stops or is suspended
5. Cont: the process is continued if it is already stopped



* One way to programmatically send a signal to a process is to use kill(). This is the most common way as it sends a signal to a specified process, or all members of a specified process group. The signature is: int kill(pid\_t pid, int sig);



Example:

\#include <stdio.h>

\#include <unistd.h>

\#include <sys/types.h>

\#include <signal.h>

 

int main() {

    pid\_t my\_pid = getpid();



    printf("The process ID is: %d\\n", my\_pid);

    printf("Sending SIGTERM...\\n");



    //send the SIGTERM signal to the current process

    int result = kill(my\_pid, SIGTERM);



    if (result == -1) {

        perror("kill failed");

    }



    //the action for SIGTERM is to terminate the process

    //so the program will end right after the kill() call

    return 0;

}



* One way to send a signal to a process from the command line is to use the kill command. It is similar to the kill() function in a program, but it can directly be done on the terminal.



Examples:

kill 4789 (kill sends SIGTERM by default to end the process. It is a polite request)

kill -9 4789 (this forces the process to stop if only kill does not work)

kill -STOP 4789 (this forces the process to pause)



POSIX Signal Types

* SIGINT: signal that is sent when Ctrl+C is pressed. It requests to interrupt and terminate the process. The default disposition is to terminate the process, and it can be overridden because it is just a request, not a hard command.
* SIGTERM: signal that is sent by the kill command. It is the polite way to request the process to terminate, and the disposition is terminating the program. It can be overridden since it is a request.
* SIGUSR1: signal that is user-defined and can be used for custom purposes. Its default disposition is to terminate the process, and it can be overridden since it would be useless if it could not.
* SIGKILL: signal which force quits the process. Its default disposition is to terminate the process, and it cannot be overriden due to its non-negotiable condition. This is a guaranteed way to remove/delete the process. It is not catchable.
* SIGSTOP: signal which forces the process to pause. Its default disposition is to suspend (stop) the process, and it cannot be overridden since it is non-negotiable. This is a guaranteed way to pause the process. It is not catchable.





**Part 2**

After removing exit(1) from the handle\_signal function, the program kept running "Sleeping" even after SIGINT was sent. I used Ctrl + C to send the SIGINT signal. When doing this, the program caught the signal and printed "Received a signal" and continued to run.

Since this method did not work, I used the kill command (kill 9659) to send SIGTERM, which terminates the process by finding its PID. Because the program does not handle SIGTERM, the process terminated successfully and the terminal printed "Terminated."

 Another way to terminate the program is to send SIGKILL (kill -9 9659), which forces the process to terminate and the terminal prints "Killed."



**Part 3**

alarm() and SIGALRM work together as a simple "alarm clock" mechanism.

alarm(unsigned int seconds): sends the SIGALRM signal after a specified time in seconds.

SIGALRM (Signal 14): the signal itself, just like SIGINT or SIGTERM. It terminates the process.





Because the exit function was not added in the signal handler function, the program keeps executing since it is an infinite loop. This happens because when the signal handler returns, the program will re-execute the exact instruction that caused the fault. This causes another SIGSEGV and the loop repeats. The program had to be terminated wth Ctrl + C.



The sigaction() function allows you to have more control over the handling of signals than signal() function. Sigaction provides more information on the signal, such as the sender's PID. It also allows you to control other things, such as blocking other signals while the signal handler is running.

The sigaction structure is where all the information is contained, and this struct is passed to the sigaction() function. It consists of:



struct sigaction {



&nbsp;   //The signal handler

&nbsp;   union {

&nbsp;       void (\*sa\_handler)(int);

&nbsp;       void (\*sa\_sigaction)(int, siginfo\_t \*, void \*);

&nbsp;   } \_\_sigaction\_handler;



&nbsp;   //mask of signals to block during handler execution

&nbsp;   sigset\_t sa\_mask;



&nbsp;   //set of flags to modify the signal's behavior 

&nbsp;   int sa\_flags;

}



