'''
In this exercise, we are going to show one reason the nonce must be changed every time
'''

from Crypto.Cipher import AES
import binascii

key = b'Super Secret Key'
iv = b'AAAAAAAA'

def pad_message(message):
    pad_len = 16 - (len(message) % 16)
    return message + b"\x00"*pad_len

def counter_crypt(data):
    aes = AES.new(key, AES.MODE_CTR, nonce=iv)
    return aes.encrypt(data)

def xor_bytestrings(xs, ys):
    return bytes([ x^y for x,y in zip(xs,ys) ])

#####################################################################################
#ONLY EDIT THIS FUNCTION
#Hint: the only function you need to call is xor_bytestrings
def decrypt_bad_counter(your_message, your_ciphertext, secret_ciphertext):
    pass

#####################################################################################

def main():
    secret_message = b"Integrity first. Service before self. Excellence in all we do."
    secret_ciphertext = counter_crypt(pad_message(secret_message))
    your_message = input("Please enter your message: ").encode()
    your_ciphertext = counter_crypt(pad_message(your_message))

    print(f"Secret ciphertext is:\t{binascii.hexlify(secret_ciphertext)}")
    print(f"Your message is:\t\t{your_message} {binascii.hexlify(your_message)}")
    print(f"Your ciphertext:\t\t{binascii.hexlify(your_ciphertext)}")
    decrypted_ciphertext = decrypt_bad_counter(your_message, your_ciphertext, secret_ciphertext)
    print(f"Decrypted ciphertext:\t{decrypted_ciphertext} {binascii.hexlify(decrypted_ciphertext)}")

if __name__ == '__main__':
    main()