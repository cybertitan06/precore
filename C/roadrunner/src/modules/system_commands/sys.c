/**
 * sys.c contains all of the functionality for the system commands.
 * @file sys.c
 */

#include <sys.h>

#define PLACEHOLDER "replace"
#define PLACEHOLDER_SIZE 7

// processlist helper functions
static uint32_t is_pid_folder(char *dir);
static uint32_t parse_pid_stat(char *proc_pid_dir, pid_stat_t *pid_stats);
static uint32_t parse_pid_owner(char *proc_pid_dir, pid_stat_t *pid_stats);
static uint32_t parse_pid_cmdline(char *proc_pid_dir, pid_stat_t *pid_stats);
static uint32_t return_plist_line(char *proc_pid_dir, char *proc_line);

// netstat helper functions
static uint32_t parse_conn_line(char *line, tcp_conn_t *connections);
static char *hex_to_ipaddr(u_int32_t ip_h);
static void free_connections(tcp_conn_t *connections);
static void print_connections(tcp_conn_t *connections, char *print_line);


/************************INSTRUCTIONS*****************************

Build 4 commands:
    hostname                Returns hostname
    invoke                  Returns shell command output
    proclist                Returns process list or proc info
    netstat                 Returns netstat

Hostname Functions:
    hostname_command

Invoke Functions
    invoke_command

Proclist Functions:
    process_list_command
        is_pid_folder
        return_pslist
            parse_pid_stat
            parse_pid_owner
            parse_pid_cmdline

Netstat Functions:
    get_netstat_command
        parse_conn_line
            hex_to_ipaddr
        print_connections
        free_connections

If you want to make use of the test harness, do not remove the MACROs. 
The macros will perform the required functionality for the function. 
See the defined macros in sys.h for more information.

*****************************END**********************************/

/**
 * @brief Returns hostname of host machine
 * @param cmd (in) a pointer to the command
 * @return Response where the message is the hostname
 * @return HOSTNAME_ERROR_MSG on error
 */
Response *hostname_command(Command *cmd)
{
    int32_t ret_code;
    char hostname[BUFF_MAX + 1] = {0};
    Response *rsp = NULL;
    
    // Get hostname
    HOSTNAME_MACRO(hostname, BUFF_MAX + 1, ret_code)
    // remove the PLACEHOLDER values and put the hostname string and its size

    //gethostname(hostname, sizeof(hostname));    

    //Check for error messages
    if (ret_code == -1){
        rsp = alloc_response(ret_code, HOSTNAME_ERROR_MSG, strlen(HOSTNAME_ERROR_MSG) + 1);
    } else
        rsp = alloc_response(0, hostname, strlen(hostname) + 1);

    return rsp;
}

/**
 * @brief Builds formatted process list in one heap buffer and passed to Response
 * arg[1] = "" (empty) - Return full process list
 * arg[1] = pid - Return process information for just 1 pid
 * 
 * @param cmd (in) Command selected with args
 * @return Response* Formatted process list on success
 * @return Response* PROCESS_ERROR_MSG on error
 */
Response *process_list_command(Command *cmd)
{
		if (NULL == cmd){
			//return error Response
		}

    // Use this Format string to print your output header  (needed to pass the test)
    // Uncomment the line below
    // snprintf(process_list, PROCESS_LINE_MAX + 1, "%-10s %-8s %-8s %-20s %s\n", "OWNER", "PID", "PPID", "PNAME", "CMDLINE");

    // Return process list for just 1 pid
		if (0 != cmd->args_len){
			//validate cmd->args aren't garbage
			if(!is_pid_folder(cmd->args)){
				//return error Response
			}
			//instantiate pid struct
			pid_stat_t pid_stats = {0};
			//parse_pid_stat will give us the pid, ppid, and pname
			if(!parse_pid_stat(cmd->args,&pid_stats)){
				//return error Response
			}
			//parse_pid_cmdline will give us the cmdline

			//

			
		}
    // or
		else {
    	// process all directories
		}			
    // Return process list

    
    Response *rsp = alloc_response(0, PLACEHOLDER, PLACEHOLDER_SIZE + 1);    
    return rsp;
}

/**
 * @brief Checks if folder contains all digits
 * @param entry (in) dirent structure - returned from readdir
 * @return uint32_t Returns 1 on success, 0 on failure
 */
static uint32_t is_pid_folder(char *dir)
{    
    int i;
	for(i = 0; i <strlen(dir); i++)
    {
		if(0x40 < dir[i] || dir[i] < 0x30)
        {
			return false;
		}
    }
	return true;
}


/**
 * @brief Loads struct pid_stat_t with information for 1 process from /proc
 * the contents of /proc/<PID>/stat look like this: 
 * 1137 (snapfuse) S 1 1137 1137 0 -1 4194624 10176 0 0 0 55 3 0 0 20 0 1 0 42688 4894720 461 18446744073709551615 1 1 0 0 0 0 0 4096 16387 0 0 0 17 1 0 0 0 0 0 0 0 0 0 0 0 0 0
 *
 *  processid -> pid
 *  parentpid -> ppid
 *  process name -> comm
 *  State of process -> state
 *
 * @param proc_pid_dir (in) Directory of process
 * @param pid_stats (out) pointer to struct pid_stat_t
 * @return Returns 0 if unable to process information
 * @return Returns 1 if successful
 */
static uint32_t parse_pid_stat(char *proc_pid_dir, pid_stat_t *pid_stats)
{
    // read process statistics /proc/<pid>/stat
    char *raw_pid_stats = NULL;
    uint32_t contents_size = 0;

    /* Open and read /proc/<pid>/stat, Output are statistics, delimited by " "
     *  "man proc" for details */
    READ_PROC_MACRO(proc_pid_dir, &raw_pid_stats, contents_size);

    // load pid_stats with information

    return 1;
}

/**
 * @brief Opens /proc/<pid>/loginuid to determine owner of process.
 * Sometimes loginuid returns -1 -> sets owner to "unk"
 * Loads pid_stats->owner with the owner of the process
 * NOTE: Loginuid isn't always accurate to the owner of the process
 * 
 * @param proc_pid_dir (in) loginuid path (ex. /proc/<pid>/loginuid)
 * @param pid_stats (out) struct with process information - defined in sys.h
 * @return uint32_t returns 0 if unable to parse owner
 * @return uint32_t returns 1 on success
 */
static uint32_t parse_pid_owner(char *proc_pid_dir, pid_stat_t *pid_stats)
{
    // Initialize Variables
    char *owner = NULL;
    uint32_t contents_size = 0;

    // call getpwuid(uid)
    READ_LOGINID_MACRO(proc_pid_dir, &owner, contents_size);
    return 1;
}

/**
 * @brief Opens /proc/<pid>/cmdline to get the exact command that kicked off the process
 * Loads pid_stats->cmdline with the command
 * 
 * @param proc_pid_dir (in) path to cmdline (ex. /proc/<pid>/cmdline)
 * @param pid_stats (out) struct with process information - defined in sys.h
 * @return uint32_t returns 0 if unable to parse cmdline
 * @return uint32_t returns 1 on success
 */
static uint32_t parse_pid_cmdline(char *proc_pid_dir, pid_stat_t *pid_stats)
{
    // Initialize variables
    char *cmdline = NULL;
    uint32_t contents_size = 0;

    // read proc_dir and returns the cmdline string
    READ_CMDLINE_MACRO(proc_pid_dir, &cmdline, contents_size);
    return 1;
}

/**
 * @brief Returns a formatted line with all corresponding pid information 
 * @param pid (in) process id (string of digits)
 * @param proc_line (out) formatted string with all process information
 * @return uint32_t length of proc_line (0 on failure)
 * *NOTE: Caller needs to free return
 */
static uint32_t return_plist_line(char *pid, char *proc_line)
{
    //parse_pid_stat
    //parse_pid_owner
    //parse_pid_cmdline

    /* Format process line for return
    snprintf(proc_line, PROCESS_LINE_MAX, "%-10s %8d %8d %-20s %s\n",
             pid_stats->owner,
             pid_stats->pid,
             pid_stats->ppid,
             pid_stats->comm,
             pid_stats->cmdline);*/
    return 1;
}

/**
 * @brief Calls Popen to execute shell commmand, not built for interactive cmds
 * 
 * @param cmd (in) 
 * @return Response* Returns command output on success or failure
 */
Response *invoke_command(Command *cmd)
{
    Response *rsp = NULL;
    // Use the man pages to learn about he Popen command~~a



    rsp = alloc_response(0, PLACEHOLDER, PLACEHOLDER_SIZE + 1);
    return rsp;
}

/**
 * @brief Opens /proc/net/tcp and sends current tcp connections
 * 
 * @param cmd (in)
 * @return Response* returns formatted tcp socket information on success
 * @return Response* returns NETSTAT_ERROR_MSG on failure
 */
Response *get_netstat_command(Command *cmd)
{
    char *tcp_stream = NULL;
    uint32_t contents_size = 0;
    tcp_conn_t *connections = NULL;
    
    // Read /proc/net/tcp and get stat information
    READ_NET_STAT("/proc/net/tcp", &tcp_stream, contents_size);

    // Set up header for netstat, use this line for the test harness
    // Uncomment the line below
    // snprintf(netstat_buff, BUFF_MAX, "%-21s %-21s %-10s %-20s %10s\n", "LOCAL", "REMOTE", "STATUS", "OWNER", "INODE");

    // Iterate through each line of /proc/net/tcp. The lines are delimited by newline characters ('\n')	
    // Create a linked list of tcp_conn_t structures to hold the /proc/net/tcp data, one struct per line.
    // Skip the first line with the headers, we won't need them.

    /*
     * 	for line in tcp_stream:
	 * 		allocate a tcp_conn_t struct
	 * 		tcp_conn_t connection = calloc(1,sizeof(tcp_conn_t))
	 *
	 * 		skip first line
     *		if (line is first_line)	{continue}
	 *
	 *		parse all the other lines with parse_conn_line to populate your struct
     *		ret = parse_conn_line(line,connection)
	 *
	 *		As you create more connection structs, make sure they point to each next one
	 *		refer to the definition of the tcp_conn_t structure in sys.h
	 *
	 *		You should now have a linked list of tcp_conn_t structs holding all the data from tcp_stream
     */


    
    // Walk through linked list. 
	tcp_conn_t *pConn = connections;
    while (NULL != pConn)
   
    {
        //format output
		//Use the snprintf statement above to format each line and append it to the output. Each line should be separated by a newline character

		//copy line to buffer
		//pConn = pConn->next
    }

    // set up response
    Response *rsp = alloc_response(0, PLACEHOLDER, PLACEHOLDER_SIZE + 1);
    return rsp;
}

/**
 * @brief Parse network connections from /proc/net/tcp and set relevant fileds in tcp_conn_t struct
 * 
 * @param line (in) Line of network connections from /proc/net/tcp (1 network connection at a time)
 * @param connections (out) linked list structure to hold network info for each connection
 * @return uint32_t returns 1 on success
 * @return uint32_t returns 0 on failure
 */
static uint32_t parse_conn_line(char *line, tcp_conn_t *connections)
{

    uint32_t uid = 0;
    struct passwd *pwd = NULL;

    // Get username from uid - calls getpwuid
    GET_UID_MACRO(uid, pwd);
    // fill out relevan information in the connections struct
    return 1;
}

/**
 * @brief Format a netstat connection
 * 
 * @param connections (in) structure with connection information - defined in sys.h
 * @param print_line (out) formatted connection line
 */
static void print_connections(tcp_conn_t *connections, char *print_line)
{
    /* Format line ("-" makes it left justified)
    * Need this format for the test harness
    * Uncomment the line below
    snprintf(print_line, BUFF_MAX, "%15s:%-5d %15s:%-5d %-10s %-20s %10ld\n",
                connections->local_addr,
                connections->local_port,
                connections->remote_addr,
                connections->remote_port,
                status,
                connections->owner,
                connections->inode);*/
    return;
}

/**
 * @brief Free connection linked list
 * 
 * @param connections (in) structure with connection information - defined in sys.h
 */
static void free_connections(tcp_conn_t *connections)
{
    return;
}

/**
 * @brief convert network order hex to ipv4 string notation
 *       This function is useful to make the hex representation found in
 *       /proc/net/tcp human readable
 * 
 * @param ip_h (in) hex value found in /proc/net/tcp
 * @return char* ipv4 string notation
 */
static char *hex_to_ipaddr(uint32_t ip_h)
{    
    return "0.0.0.0";
}
