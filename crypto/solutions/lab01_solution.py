'''
In this exercise, we are going to load an image from a file, encrypt it, and then save the image again
Here is a reference for the correct code: https://www.pycryptodome.org/src/examples#encrypt-data-with-aes
'''

from Cryptodome.Cipher import AES
from resources.image import Picture

key = b'Super Secret Key' # please fill in this value
aes = AES.new(key, AES.MODE_ECB) # use this object within the encrypt and decrypt functions

def encrypt(data):
    encrypted_data = aes.encrypt(data)

    return encrypted_data

def decrypt(data):

    decrypted_data = aes.decrypt(data)
    
    return decrypted_data

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def main():
    pic = Picture()
    image_bytes = pic.open_image("./resources/tuxwhitebg.jpg")
    encrypted_image_bytes = encrypt(image_bytes)
    pic.save_image(encrypted_image_bytes, "./results/encrypted_image.png")
    decrypted_image_bytes = decrypt(encrypted_image_bytes)
    pic.save_image(decrypted_image_bytes, "./results/decrypted_image.png")

if __name__ == '__main__':
    main()

### TALKING POINTS
# Key lengths
# The final image
