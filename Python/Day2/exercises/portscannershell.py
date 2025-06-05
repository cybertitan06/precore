#!/usr/bin/env python3
import argparse
import socket
import sys


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--ip", required=True,
                        type=str, help="The target IP")
    return parser.parse_args()


def scan_tcp(target_ip, start_port, end_port):
    try:
        for port in (start_port,end_port):
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            socket.setdefaulttimeout(1)

            result = s.connect_ex((args, port))
            if result == 0:
                print("Port {} is open".format(port))
            s.close()
    except KeyboardInterrupt:
        print("\n Exiting Program")
        sys.exit()
    pass

if __name__ == "__main__":
    args = get_args()
    scan_tcp(args, 1025, 8000)


