#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Search "Beej's Guide to Network Programming" online if you need help! 
//It's an amazing resource
int main()
{
    int sockfd = 0;
    size_t bytesReceived = 0;
    char recvBuf[1024] = {0}; // Implicitly calls memset
    struct sockaddr_in serveraddr = {0}; // Implicitly calls memset

    // Create a socket and assign it to sockfd
    // hint: socket(2)
    if (sockfd == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }

    // Fill out sockaddr_in with
    // the details for a TCP connection to: 128.138.140.44:13
	// This is the address of a NIST server 
	// at the University of Colorado, and port 13 serves Daytime protocol.
	// Effectively, we're just asking a time keeping server for the time.

    // Use serveraddr with the connect call
    // hint connect(2)
    // hint again: cast the sockaddr_in into a struct sockaddr
    if (connect() != 0)
    {
        printf("Could not connect!\n");
    }

    // Read it to a buffer with recv(2)
    // Print it out
    printf("Received: %s\n", recvBuf);

    // Close the socket with close(2)

    return 0;
}
