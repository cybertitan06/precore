/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <poll.h>

#include <arpa/inet.h>

#define MAXDATASIZE 256 // max number of bytes we can get at once 


int connectToServer(char *host,char *port);

int main(int argc, char *argv[])
{
	if (2 != argc){
		printf("usage: ./client <port>\n");	
		return 1;
	}
	char *port = argv[1];
	//connect to server
    int sockfd = connectToServer("127.0.0.1",port);

	//poll can watch multiple file descriptors (fd) for events
    //use poll to watch both sockfd and stdin
	//poll takes three arguments:
		//1. an array of type struct pollfd (there should be one per fd you want to monitor)
		//2. the length of the array (e.g. the number of fd's you are monitoring)
		//3. the amount of time to poll before giving up and returning 0 (e.g. none of the fd's did anything)
			//note that a negative value for timeout will make poll wait for an event indefinitely

    struct pollfd fds[2];
    fds[0].fd = 0;
    fds[1].fd = sockfd;
    fds[0].events = POLLIN; //the POLLIN event just means there is data that can be read on the fd
    fds[1].events = POLLIN;
    nfds_t nfds = 2;
    int timeout = -1;
    int poll_status;
    char recv_buf[MAXDATASIZE] = {0};
    char send_buf[MAXDATASIZE] = {0};
    int bytes;
    
    //main loop
    while(true){
		poll_status = poll(fds,nfds,timeout);

		//check for data from stdin
		if (POLLIN == fds[0].revents){
	    	bytes = read(0,send_buf,MAXDATASIZE);
			if (bytes < 1){
			    printf("error reading from stdin\n");
				return 1;
			}
			send(sockfd,send_buf,strnlen(send_buf,MAXDATASIZE),0);
			memset(send_buf,0,MAXDATASIZE);
		}
		//check for data from socket
		if (POLLIN == fds[1].revents){
			bytes = recv(sockfd,recv_buf,MAXDATASIZE,0);
			if (bytes < 0 ){
				printf("error reading from socket: %d\n",bytes);
				return 1;
			}
			if (0 == bytes){
				printf("remote server disconnected\n");
				return 0;
			}
			printf("%s",recv_buf);
			memset(recv_buf,0,MAXDATASIZE);
		}	
    }
    close(sockfd);
    return 0;
}



int connectToServer(char *host,char *port){

    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return -1;
    }

    freeaddrinfo(servinfo); // all done with this structure
    printf("got socket %d\n",sockfd);
    return sockfd;

}
