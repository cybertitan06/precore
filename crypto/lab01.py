'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Crypto.Cipher import AES
from image import Picture

key = b'this_is_my_encryption_key' # please fill in this value
aes = AES.new(key, AES.MODE_ECB) # use this object within the encrypt and decrypt functions

def encrypt(data):

    # Fill in this function with encryption of data using the aes object

    return encrypted_data

def decrypt(data):

    # Fill in this function with decryption of the data using the aes object

    return decrypted_data

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def main():
    pic = Picture()
    image_bytes = pic.open_image("./tuxwhitebg.jpg")
    encrypted_image_bytes = encrypt(image_bytes)
    pic.save_image(encrypted_image_bytes, "./encrypted_image.jpg")
    decrypted_image_bytes = decrypt(encrypted_image_bytes)
    pic.save_image(decrypted_image_bytes, "./decrypted_image.jpg")

if __name__ == '__main__':
    main()