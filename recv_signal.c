/**
 * File: recv_signal.c
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of program: handles SIGUSR1 signal and prints sival_int
 */

 #include <stdio.h>
 #include <unistd.h>     
 #include <signal.h>     
 #include <string.h>   
 #include <sys/types.h> 



 void handle_sigusr1(int sig, siginfo_t *info, void *ucontext){

    int sival_val = info->si_value.sival_int; //sival_int inside info 
    printf("The received sival_int value is: %d\n", sival_val);
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