#!/usr/bin/env python3
import argparse
import socket


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--ip", required=True,
                        type=str, help="The target IP")
    return parser.parse_args()


def scan_tcp(addr, start_port, end_port):
    pass

if __name__ == "__main__":
    args = get_args()

