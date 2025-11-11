/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Zoya Mumtaz
 * 
 * Brief summary of modifications: added a signal handler and signal()
 */


#include <stdio.h>
#include <signal.h>

void handle_segfault(int sig){
    puts("The segmentation fault was received.");
}

int main (int argc, char* argv[]) {
    //register the handler 
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}