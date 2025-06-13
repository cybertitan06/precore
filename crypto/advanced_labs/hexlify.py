import binascii
import sys

def main():
    match (len(sys.argv)):
        case 1:
            message = input("Please provide the message you want to hexlify: ").encode()
        case 2:
            message = sys.argv[1].encode()
        case _:
            print("Too many arguments")
            return
    print(binascii.hexlify(message))

if __name__ == "__main__":
    main()