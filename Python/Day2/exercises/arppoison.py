
#!/usr/bin/env python3
import time
import sys
import scapy.all as scapy
 
 
def get_mac(ip): 
    """Here is where an ARP request is constructed and broadcast out to recieve the target ip's MAC address"""
  
def spoof(target_ip, spoof_ip): 
     """" 
    Here the ARP packet is set to response and destination is set to the target 
    either it is for victim or router and the hardware destination is the MAC
    address of the IP provided and the source is the spoofing ip to manipulate 
    in the packet
    """
    
  
def restore(destination_ip, source_ip): 
    """here the target is send the correct IP-MAC address association to restore the ARP table. 
    This function is not required for the poision to succeed"""

    pass


def main():
    """The main function will continuousl loop to spoof the addresses of both the target server and target client
    This must occur continuously otherwise the ARP tables will automatic refresh to their correct state"""
    pass


if __name__ == "__main__":
    main()
