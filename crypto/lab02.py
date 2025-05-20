'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Crypto.Cipher import AES
from image import Picture

key = b'' # please fill in this value
iv = b'' # please fill
nonce = b'' # please fill

def encrypt(data):
    aes = AES.new(key, AES.MODE_ECB) # edit this object to use counter mode with your custom nonce/IV
    encrypted_data = aes.encrypt(data)

    return encrypted_data

def decrypt(data):
    aes = AES.new(key, AES.MODE_ECB) # edit this object to use counter mode with your custom nonce/IV
    decrypted_data = aes.decrypt(data)

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