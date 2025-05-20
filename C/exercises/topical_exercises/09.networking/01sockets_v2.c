#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
	char *ip = "128.138.140.44";
	char *port = "13";
	
	int status;
	struct addrinfo hints;
	struct addrinfo *results;

    //populate your hints struct to use with getaddrinfo
    
    //initialize hints struct with memset

    //set hints.ai_family. IPv4 or IPv6 is fine
	//set hints.ai_socktype for a tcp stream socket
	//set hints.ai_flags. 

	//use getaddrinfo to fill out servinfo struct, using hints struct
	if (0 != (status = getaddrinfo(<fill in args>))) {
		printf("error: getaddrinfo\n");
		return 1;
	}


    // Create a socket and assign it to sockfd. sockfd return -1 on error
    // hint: socket(2)

    int sockfd = 0;
	struct addrinfo *p;

	//loop through structs stored in results until one gives us a socket that connects successfully
	for (p = replaceme; p != replaceme; p = replaceme) {
		sockfd = socket(<fill in args>);
		if (/*check for bad return from socket()*/)
		{
			printf("Could not create socket\n");
			continue;
		}
		//Try to connect with our socket
		status = connect(<fill in args>);
		if (/*check for bad return from connect()*/) {
			printf("Unable to connect to %s:%s\n",ip,port);
			continue;
		}
		//if we made it here, we have a good socket.
		break;
	}

	//free the structs that were made for us earlier. Use freeaddrinfo

	//check whether we were successful or if we ran out of tries
	if (<replaceme>){
		printf("ERROR: unable to get connected socket\n");
		return 1;
	}

	char recvBuf[256] = {'\0'};	
    // Read it to a buffer with recv(2)
	recv(<fill in args>);   //receive into recvBuf. You can assume a max 
                            //msg length of 256 bytes
    // Print it out
    printf("Received: %s\n", recvBuf);

    // Close the socket with close(2)
	close(<replaceme>);
    return 0;
}
