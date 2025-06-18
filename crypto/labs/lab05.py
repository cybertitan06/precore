'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Cryptodome.Cipher import AES
from Cryptodome.Hash import HMAC, SHA256
from resources.image import Picture

key = b'AAAAAAAAAAAAAAAA'
cipher = AES.new(key, AES.MODE_CTR)


def create_hmac(data):
    hmac = HMAC.new(data, digestmod=SHA256)
    ciphertext = cipher.encrypt(data)

    tag = hmac.update(cipher.nonce + ciphertext).digest()
    return tag

def verify_hmac(data, tag):
    hmac = HMAC.new(data, digestmod=SHA256)
    ciphertext = cipher.encrypt(data)

    tag = hmac.update(cipher.nonce + ciphertext).verify(tag)
    return tag

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def main():
    pic = Picture()
    image_bytes = pic.open_image("./resources/tuxwhitebg.jpg")
    tag = create_hmac(image_bytes)
    try:
        verify_hmac(image_bytes, tag)
        print("Congratulations")
    except:
        print("Failed to verify tag")


if __name__ == '__main__':
    main()
