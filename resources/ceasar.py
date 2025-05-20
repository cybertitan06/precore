#!/usr/bin/env python3

def encrypt(text, shift):
    #Encrypts using Caesar chipher with shift.
    result = ""
    
    for char in text:
        # Encrypts based on asci table locations 
        if char.isupper():
            result += chr((ord(char) + shift - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + shift - 97) % 26 + 97)
        else:
            result += char
    
    return result


def decrypt(text, shift):
    #Decrypts the given text using Caesar Cipher(rotation) shift.
    return encrypt(text, -shift)


def main():
    choice = input("(e)ncrypt or (d)ecrypt? ")
    if choice.lower() not in ['e', 'd']:
        print("Invalid choice!")
        return

    text = input("Enter the text: ")
    shift = int(input("Enter the shift value: "))

    if choice.lower() == 'e':
        encrypted_text = encrypt(text, shift)
        print(f"Encrypted text: {encrypted_text}")
    else:
        decrypted_text = decrypt(text, shift)
        print(f"Decrypted text: {decrypted_text}")


if __name__ == "__main__":
    main()
