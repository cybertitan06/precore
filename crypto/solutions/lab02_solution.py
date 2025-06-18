'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Cryptodome.Cipher import AES
from resources.image import Picture

key = b'AAAAAAAAAAAAAAAA' # please fill in this value
iv = b'AAAAAAAA' # please fill
nonce = b'BBBBBBBB' # please fill

def encrypt(data):
    print(iv)
    aes = AES.new(key, AES.MODE_CTR, initial_value=iv, nonce=nonce) # edit this object to use counter mode with your custom nonce/IV
    encrypted_data = aes.encrypt(data)
    print(aes.nonce)

    return encrypted_data

def decrypt(data):
    print(iv)
    aes = AES.new(key, AES.MODE_CTR, initial_value=iv, nonce=nonce) # edit this object to use counter mode with your custom nonce/IV
    print(aes.nonce)
    decrypted_data = aes.encrypt(data)

    return decrypted_data

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def main():
    pic = Picture()
    image_bytes = pic.open_image("./resources/tuxwhitebg.jpg")
    encrypted_image_bytes = encrypt(image_bytes)
    pic.save_image(encrypted_image_bytes, "./results/encrypted_image2.jpg")
    decrypted_image_bytes = decrypt(encrypted_image_bytes)
    pic.save_image(decrypted_image_bytes, "./results/decrypted_image2.jpg")

if __name__ == '__main__':
    main()
