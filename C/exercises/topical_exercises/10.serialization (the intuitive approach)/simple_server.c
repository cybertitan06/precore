/*
** server.c -- a stream socket server demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "3490"  // the port users will be connecting to

#define BACKLOG 10   // how many pending connections queue will hold

void sigchld_handler(int s)
{
    // waitpid() might overwrite errno, so we save and restore it:
    int saved_errno = errno;

    while(waitpid(-1, NULL, WNOHANG) > 0);

    errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
    int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    rv = getaddrinfo(NULL,PORT,&hints,&servinfo);
    if (0 != rv) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
	sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (-1 == sockfd) {
            perror("server: socket");
            continue;
        }

	rv = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));
        if (-1 == rv) {
            perror("setsockopt");
            exit(1);
        }
	rv = bind(sockfd,p->ai_addr,p->ai_addrlen);
        if (-1 == rv) {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }
    //if we made it here, that means we found a result we could bind to! (or we ran out results to try)
    freeaddrinfo(servinfo); // all done with this structure

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    char buf[1024] = {0};
    int bytes_recv = 0;
    int bytes_send = 0;

    while(1) {  // main accept() loop
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family,
            get_in_addr((struct sockaddr *)&their_addr),
            s, sizeof s);
        printf("server: got connection from %s\n", s);
	
	while(1){
		bytes_recv = recv(new_fd,buf,1024,0);
		if (bytes_recv < 1){
			printf("recv error\n");
			return 1;
		}
		printf("%s\n",buf);
		fgets(buf,1024,stdin);
		send(new_fd,buf,strlen(buf),0);	
	}		
        close(new_fd);  // parent doesn't need this
    }

    return 0;
}
