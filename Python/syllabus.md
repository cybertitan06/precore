# Pre-core Python & Networking Syllabus 2024

## Purpose

**BLUF this course only covers the topics the instructors have deemed most relevant to prepare students for precore**

The purpose of this lesson set is to provide the students a **primer** on basic topics relating to Python programming languages as well basic topics relating to networking fundamentals.
This class will not cover every possible Python and networking topic that the students might need to know. It only serves as course to prepare students for the lessons an work they will
encounter during Core Training. 

## LECTURE SLIDES

All the lecture slides can be found at the google drive link below:

https://drive.google.com/drive/folders/1Nt7SNJEcKcF2DsgmQClhErHgIPz0V5zJ?usp=drive_link

## General Schedule

This portion of Pre-core will take place from 05JUN24-10JUN24.

Each day will follow the typical schedule:
0800-1000: Morning Lecture
1000-1200: Exercises
1200-1300: Lunch Break
1300-1400: Afternoon Lecture (if there is one)
1400-1600: Exercises

### Day 1 Topics Covered
Fundamental Python:
    - Basic Data Types
    - Strings
    - Lists
    - Sets
    - Dictionaries
    - Comprehensions 
    - Control Flow
    - Functions
    - Data Structures
    - Importing/Using Modules
    - File Operations

### Day 1 End of Day Exercises
The Basics - precore/Python/Day1/exercises/basics.md
    - This list of exercises are designed to flex your basic Python muscles at varying degrees of difficulty. 

Hangman - precore/Python/Day1/exercises/hangman/
    - Create the classic game hangman where the user guesses the word against the AI. Feel free to use included dictionary of words and ascii art, or make your own!
    
UBER CHALLENGE: Frogger - precore/Python/Day1/exercises/frogger-uberchallenge/
    - create the classic game frogger using the python module turtle. You will need to look up the documentation for turtle.
    
### Day 2 Topics Covered
More Python + Networking Fundamentals:
    - Argparse Python Module
    - Networking Fundamentals
        - IP Addresses & MAC Addresses
        - TCP & UDP Protocol
        - HTTP, HTTPS, SSH, Telnet, ICMP, ARP, Common Ports
    - Wireshark
        - What it is and basic usage
    - Scapy Python Module
        - What is it, how to use it and how it can benefit YOU
    - CNO Concept
        - Arp Poisoning
        
### Day 2 End of Day Exercises
Port Scaner - percore/Python/Day2/exercises/portscanner.py
    - Create a port scanner that will attempt to find all open ports on our server. Once you have identified the open port user Wireshark to filter on that port and discover the hidden message.

Arp Poisoner - precore/Python/Day2/exercises/arppoisoner.py
    - Create a Python script to ARP poison your neighbors computer and DOS them. Use scapy. **Please do not take down the gateway and DOS everyone.**
    
UBER CHALLENGE: Arp Poisoner Hardmode- precore/Python/Day2/exercises/arpoisoner-uberchallenge/
    - Create the same arp poisoner as you did in the previous exercise but this time use raw sockets. **Please do not take down the gateway and DOS everyone.**
    
### Day 3 Topics Covered
Encryption:
    - Caesar Cipher, XOR, TLS/SSL
CNO Concept:
    - MiTM
        - What is it, why we do it, how to do it
        
### Day 3 End of Day Exercises
MiTM - precore/Python/Day3/exercises/MiTM.py
    - Using your gained knowledge from yesterday's and today's lecture, create a Python script to connect to the server, and get the flag.
    
UBER CHALLENGE: MiTM Encrypted - precore/Python/Day3/exercises/MiTM-uberchallenge/
    - Using your gained knowledge from yesterday's and today's lecture, create a Python script to connect to the encrypted server, and get the flag.
    
### Day 4 Topics Covered
Python Topics:
    - Concurrency 
        - Multiprocessing, Multithreading, AsyncIO
        
    - Final Project ACME:
        - Learn what you need to know to work on and complete the ACME server for Capstone Project
    
### Day 4 End of Day Exercises
Work on ACME! - precore/Python/ACME/src/main.py
    - Using everything you've learned from the past 3 days, work on ACME, and whatever else you want.

    
