/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of modifications: removed the exit(1) from handle_signal()
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message
 */
void handle_signal() {
    printf("Received a signal\n");
    //removed exit here
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);


    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}