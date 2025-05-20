/** 
 * Create a C program that connects to this server and receives the serialized data from the server described in 02_data_server.c
 * Your program should satisfy the following conditions.
 *      1. The program connects to port 8080 TCP of the server on any interface
 *      2. The program received the entire chunk of data from the server.
 *      3. The program deserializes the inbound data
 *      4. The program prints the data to screen
 * The structure is provided and the data is ordered the same. 
 *
 * Hint: You can reuse some of your code from the previous exercise for this
*/

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <string.h>

#define PORT    "8080"
#define HOST	NULL

int get_bytes_from_server(char **recvBuf);
int char_deserializer(char *c, char *dest);
int short_deserializer(short *s, short *dest);
int byte_array_deserializer(char *bytes, int len, char *dest);

typedef struct {
    char name[100];
    short age;
    char grade;
    char schoolName[100];

} StudentInfo;

int main(int argc, char **argv){

	//create our struct and our recv buffer
	StudentInfo si = {0};
	char buf[300] = {0};
	int offset = 0;

	//recv bytes from server
	if (0 > get_bytes_from_server(&buf)) {
		printf("Error getting bytes\n");
		return -1;
	}
	
	//START DESERIALIZING
	//the deserializer functions that have been started for you all return the number of bytes they deserialized.
	//This way, you can use the return to update the offset with each call.
	//Hint: Use the offset with buf to ensure you are reading from the correct source address each time

	//deserialize the name
	offset += byte_array_deserializer(/*replace with correct args*/);
	//deserialize the age
	offset += short_deserializer(/*replace with correct args*/);
	//deserialize the grade
	offset += char_deserializer(/*replace with correct args*/);
	//deserialize the schoolName
	offset += byte_array_deserializer(/*replace with correct args*/);
	
	//Print results
	printf("Name: %s\nage: %d\ngrade: %d\nSchool Name: %s\n",
			si.name,
			si.age,
			si.grade,
			si.schoolName);	
	
	return 0;
}


/**
	This function takes a pointer to an output buffer
	which it will fill with the bytes it received from the server.

	It returns 0 on success, and non-zero on error
*/
int get_bytes_from_server(char **recvBuf) {
    struct addrinfo *servInfo;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family     = AF_UNSPEC;
    hints.ai_socktype   = SOCK_STREAM;
    hints.ai_flags      = AI_PASSIVE;

	//The host can be null when you are connecting to localhost	
    int errCode = getaddrinfo(/*replace with correct args*/);
    if(errCode != 0){
        fprintf(stderr,
                "Error: GetAddrinfo -> %s\n",
                gai_strerror(errCode));
        return -1;
    }

    struct addrinfo *pIter;
    int socketFileDescriptor;
    for(pIter = /*replace*/; pIter != /*replace*/; pIter = /*replace*/){
		//try and get a socket with socket()

		//check if it returned -1 and try the next struct if it did. Hint: use continue
	
		//try to connect to the server
	
		//check if connect succeeded
        }
        break;
    }
	//check whether or not you exited the loop because you successfully connected, or you ran out of tries and need to exit.

	//free the addrinfo results list

    int totalReceived = 0;
   	//start receiving bytes (make sure you receive all 300!)
	//the bytes should be stored in the output buffer 
	
	//close the socket with close()
    return 0;
}

/**
	This function takes a pointer to a char to deserialize (c),
	and a pointer to the destination it will be copied to (dest).
	It returns 1 (the size of char) 
*/
int char_deserializer(char *c, char *dest) {
}

/**
	This function takes a pointer to a short (s) to deserialize
	and a pointer to the destination it will be copied to (dest).
	It returns the size of a short.
*/
int short_deserializer(short *s, short *dest) {
}

/**
	This function takes a pointer to a byte array (bytes), the number of bytes
	to deserialize (len), and the destination to copy them to (dest).
	It returns the number of bytes it copied.
*/
int byte_array_deserializer(char *bytes, int len, char *dest) {
}

