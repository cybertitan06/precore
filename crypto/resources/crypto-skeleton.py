import socket
import binascii

def main():
    message = b"TESTTESTTESTTEST"
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    s.connect(("localhost", 22222))
    rec = s.recv(255)
    print(rec)
    s.send(message)
    rec = s.recv(255)
    print(rec)
    s.close()

if __name__ == "__main__":
    main()
