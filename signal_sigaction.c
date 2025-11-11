/**
 * File: signal_sigaction.c
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of program: handles SIGUSR1 signal and prints sender PID
 * To send the SIGUSR1 signal to process, use command: kill -SIGUSR1 <PID>
 */

 #include <stdio.h>
 #include <unistd.h>     
 #include <signal.h>     
 #include <string.h>   
 #include <sys/types.h> 



 void handle_sigusr1(int sig, siginfo_t *info, void *ucontext){

    pid_t sender_pid = info->si_pid; //si_pid inside info has process ID of sender
    printf("Signal SIGUSR1 received from sender PID: %d\n", sender_pid);
    // do not exit
 }

 int main(void){
    struct sigaction sa; //the sigaction struct
    //assign the handler to the struct's signal handler pointer
    sa.sa_sigaction = handle_sigusr1; 
    sa.sa_flags = SA_SIGINFO; //used when signal handler has 3 args

   sigaction(SIGUSR1, &sa, NULL);

   //print the PID to make it easier for the user to send signal
   printf("Program has PID: %d\n", getpid());
   
   while(1){ //infinite loop
    sleep(1);
    //does not print anything
   }

   return 0;
}
