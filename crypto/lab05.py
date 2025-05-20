'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Crypto.Cipher import AES
from Crypto.Hash import HMAC, SHA256
from image import Picture

key = b'AAAAAAAAAAAAAAAA'

def create_hmac(data):
    pass

def verify_hmac(data, tag):
    hmac = None
    hmac.hexverify(tag)

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def main():
    pic = Picture()
    image_bytes = pic.open_image("./tuxwhitebg.jpg")
    tag = create_hmac(image_bytes)
    try:
        verify_hmac(image_bytes, tag)
        print("Congratulations")
    except:
        print("Failed to verify tag")


if __name__ == '__main__':
    main()