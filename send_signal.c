/**
 * File: send_signal.c
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of program: sends SIGUSR1 signal and a random int
 * to another process (recv_signal.c executing)
 */

 #include <stdio.h>
 #include <stdlib.h>    
 #include <signal.h>   
 #include <sys/types.h>
 #include <time.h>  

 int main(int argc, char* argv[]){

    //get the argument with the PID
    if (argc != 2){
        puts("Error: Please enter the PID number");
        exit(1);
    }

    //get the pid arg and convert
    pid_t the_pid = (pid_t)atoi(argv[1]); 
    //check if the pid is valid
    if (the_pid <= 1){
        perror("Error: ");
        exit(1);
    }

    //generate random number
    //seed the generator with current time
    srand(time(NULL));
    int random = rand();

    //data to send 
    union sigval send_val;
    send_val.sival_int = random; //assign sival_int the random value
    printf("Sending SIGUSR1 to PID: %d\n", the_pid);
    printf("The number being sent is %d\n", random);

    //sigqueue to send the signal and number
    //int sigqueue(pid_t pid, int sig, const union sigval value);
    sigqueue(the_pid, SIGUSR1, send_val);
    puts("The signal has been sent to the specified PID.");
    return 0;

}