/**
 * File: signal_alarm.c
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of program: sends and handles SIGALRM
 */

 #include <stdio.h>
 #include <unistd.h>    
 #include <signal.h>   
 #include <stdlib.h>  

void handle_alarm(int sig){
    puts("The alarm signal has been received!");
    exit(0); //terminate the program

}
int main(void){
    //register the signal SIGALRM handler
    signal(SIGALRM, handle_alarm);
    printf("5 second alarm is being set . . . \n");
    alarm(5); //wait 5 seconds then send SIGALRM

    // Wait until a signal is received
    //Should print 5 times
    while(1) {
        printf("Waiting . . .\n");
        sleep(1);
    }

    return 0;

    
}