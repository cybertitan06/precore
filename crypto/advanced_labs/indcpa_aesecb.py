import binascii
from Cryptodome.Cipher import AES
from Cryptodome.Random import get_random_bytes

GAME_DESCRIPTION = \
'''
This is the IND-CPA game using a symmetric encryption scheme.
In this variant of the game, you will initially send two messages, a left message and a right message.
The game randomly picks a value of 0 or 1.
If it picked 0, then it outputs the encrypted left message.
If it picked 1, then it outputs the encrypted right message.
Your goal is to guess which one it encrypted.

To assist you, you get access to an encryption oracle, which will encrypt any message you want.
You can use the oracle as many times as you want.\n
'''

def pad_to_longest_message(left, right):
    longest_message_len = max(len(left), len(right))
    if longest_message_len % 16 != 0:
        longest_message_len = (1 + (longest_message_len // 16))*16
    left_padded = left + b"\x00"*(longest_message_len - len(left))
    right_padded = right + b"\x00"*(longest_message_len - len(right))

    return (left_padded, right_padded)

def pad_message(message):
    if len(message) % 16 == 0:
        padding = 0
    else:
        padding = (1 + (len(message)//16))*16 - len(message)
    padded_message = message + b"\x00"*padding
    return padded_message

def main():
    key = get_random_bytes(32)
    b = get_random_bytes(1) % 2
    
    print(GAME_DESCRIPTION)

    left = binascii.unhexlify(input("Please input the left message in hex: ").encode())
    right = binascii.unhexlify(input("Please input the right message in hex: ").encode())

    left_padded, right_padded = pad_to_longest_message(left, right)

    if b == 0:
        message = left_padded
    else:
        message = right_padded

    cipher = AES.new(key, AES.MODE_ECB, False)
    encrypted_message = cipher.encrypt(message)

    print(f"Here is your encrypted message: {encrypted_message}")

    choice = "0"

    while choice != "1":
        choice = input("Please choose one:\n0: Send message to encryption oracle\n1: Input guess")[0]
        match(choice):
            case("0"):
                message = binascii.unhexlify(input("Please enter your message in hex: ").encode())
                padded_message = pad_message(message)
                encrypted_message = cipher.encrypt(padded_message)
                print(f"Encrypted message: {encrypted_message}")
            case("1"):
                guess = input("Please enter your guess: (0 for left, 1 for right)")[0]
                if guess == str(b):
                    print("You are correct!")
                else:
                    print("Incorrect! Please try again.")
            case(_):
                print(f"{choice} is not a valid selection.  Please enter '0' or '1'.")



if __name__ == "__main__":
    main()