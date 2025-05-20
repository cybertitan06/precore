
# Overall Goal
By the end of C week you have completed a functional agent written entirely in C. It will be capable of the following:
1. connecting to a user specified ip and port
2. executing commands as directed by the user, and transmitted by a server (written in python)
	* sleep <n>: the agent will sleep for n seconds and send an appropriate response to the server on wake up.
	* download <filepath>: the agent will download the file located at <filepath>, and send the file contents to the server
	* upload <file contents> <filepath>: the agent will write <file contents> to the location specified by <filepath>
	* hostname: the agent will return the hostname of the local host to the server
	* processlist: the agent will gather information on processes running on the local host by parsing the files in /proc/pid, and return the information to the server
	* netstat: the agent will gather information on active network connections on the local host by manually parsing system files. refer to the FILES portion of 'man netstat'
	* invoke <cmd [args]>: the agent will execute an arbitrary command sent from the server, and return the results.
	* proxy <Lport> <Rhost> <Rport>: the agent will establish a proxy on the local host, listening on Lport, and forwarding any traffic to Rhost:Rport, and vice versa.
	* shutdown: the agent will return a final acknowledgement before terminating
3. graceful error handling 
4. clean memory management (no memory leaks!)
5. support test assertions to validate code

NOTE: Think about how you can reuse your code moving forward! For example, you are highly encouraged to write your networking code in
its own separate .c and .h files.

# Milestone Goals

## Milestone 1: 
Your program can:
1. read in user commands (with scanf or fgets) in a while loop. the program will only terminate when the user specifies the shutdown command
2. upon reading in user input, compare the input to the list of valid commands, and return an error message if an invalid command is specified
3. execute the function that corresponds to the given commands for as many commands as you can. 
- (at a minimum, try to get sleep, download/upload, invoke, and proxy done by the end of the week!)

### Milestone 1 pseudocode
``` 
pseudocode:
void main() {
  while(true) {
    user_input = take_user_input()
    if userinput == shutdown {
      break;
    }
    else {
      execute_user_command(userinput)
    }
  }
  return;
}
```
## Milestone 2:
Your program can open a socket connection on start up, it can then do everything it previously did locally,
only now the user will be sending commands over the network. (I recommend using netcat for this) 

### Milestone 2 pseudocode
```
pseudocode (assuming the client connects to the host and port specified by the user on the cmd line)
		
void main(char *host_IP, char *port) {
  connect_to_server(host_IP,port);
  while(true) {
    user_input = recv_user_input_over_the_network();
    if (user_input == shutdown) {
      break;
    }
    cmd_result = do_user_cmd();
    send_user_cmd_results_over_network(cmd_result);
  }
  return;
}
```

## Milestone 3:
Your program can parse commands according to the expected protocol, execute those commands, and transmit the results back to the server also following the appropriate
protocol.

To make executing the commands more manageable on the client side, you will use structs to hold parsed commands, and unsent results.

Here's some fun ascii art I made of these steps

step 1: server sends command to client according to protocol
```
/////////////							/////////////
/   SERVER  /							/  CLIENT   /
/           /							/	    /
/	    / -command--sent--down--wire--to--client-"ls -la"->	/	    /
/	    /							/	    /
/////////////							/////////////
```
step 2: client populates struct with command details
```
/////////////						   	//////////////
/   SERVER  /							/  CLIENT    /
/	    /							/  cmd: ls   /		
/	    / 							/  args: -la /		
/	    /							/            /
/////////////							///////////////
```
step 3: client gets result of cmd, and creates a response struct
```
/////////////							/////////////////////
/  SERVER   /							/  CLIENT	    /
/	    /							/  result: 	    /
/           / 							/    test1.txt	    /
/	    /							/    test2.txt	    /
/	    /							/    return code: 0 /
/////////////							/////////////////////
```
step 4: client sends response according to protocol
```
/////////////							/////////////
/   SERVER  /							/   CLIENT  /
/           /							/	    /
/	    / <-results:test1.txt,test2.txt-return code:0	/           /
/	    /							/	    /
/////////////							/////////////
```
## Protocol 
Here's how I recommend you format your protocol

the server will always send commands in this format:
- the total lenth of the message (unsigned int32)
- the total lenth of the command string (unsigned int32)
- the command string 
- the total length of the args string (unsigned int32)
- the args string

the client will always respond in this format:
- the total length of the message (unsigned int32)
- the total length of the response string (unsigned int32)
- the response string
- the return code (signed int 32)

Build your structs to hold these fields


### Milestone 3 Pseudocode
```
void main(char *hostip, char *port) {
  connect_to_server();
  while(true) {
    user_cmd_bytes = recv_user_cmd();
    user_cmd_struct = parse_user_cmd(user_cmd_bytes);
    if (user_cmd_struct.cmd == shutdown) {
      break
    }
    resp_struct = do_user_command(user_cmd_struct.cmd,user_cmd_struct.args);
    resp_bytes = serialize_resp_struct(resp_struct); //"But why can't I just send the struct?" I hear you ask. We'll talk about it!
    send_response_to_server(resp_bytes);
  }
  return;
}
```
