/*
 * A program that creates a pipe for communication between its child and itself.
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA "We all know Linux is great... it does infinite loops in 5 seconds"

void main(void)
{
    int sockets[2], child;
    
    /* 
     * Create a pipe and place descriptors for the sockets
     * for the two ends of the pipe. The socket whose index is returned in the
     * low word of the array is opened for reading only, while the socket in the
     * high end is opened only for writing.
     */
    if (pipe(sockets) < 0) {
        perror("opening stream socket pair");
        exit(10);
    }
    
    /* 
     * The parent creates the child with which it will share the pipe.
     * After the fork, both parent's and child's descriptor tables point to the
     * pipe. The child can then use the pipe to send a message to the parent.
     */
    if ((child = fork()) == -1)
        perror("fork");
    
    else if (child) {
        char buf[1024];
        /* This is still the parent. */
        
        /*
         * Close the write socket as it will not be used.
         * This is not reqired but it is a good practice.
         */
        close(sockets[1]);
        
        /* Read message from the child. */
        if (read(sockets[0], buf, 1024) < 0)
            perror("reading message");

        /* Print recieved message. */
        printf(">> %s\n", buf);
        
        close(sockets[0]);  /* Close socket. */
        
    } else {
        
        /* This is the child. */
        
        /*
         * Close the write socket as it will not be used.
         * This is not reqired but it is a good practice.
         */
        close(sockets[0]);
        
        /* Writes a message to the parent. */
        if (write(sockets[1], DATA, sizeof(DATA)) < 0)
            perror("writing message");
            
        close(sockets[1]);  /* Close socket. */
    }
}
