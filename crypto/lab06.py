from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Random import get_random_bytes

def create_keypair():
    keysize = 0 # fill in appropriate RSA keysize here
    return __create_keypair(keysize) # do not edit this line

def encrypt(key, data):
    pass

def decrypt(key, data):
    pass

def encrypt_and_decrypt_challenge(public_key, private_key, data):
    encrypted_data = None
    decrypted_data = None
    return decrypted_data # Do not edit this line

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def __create_keypair(keysize):
    keypair = RSA.generate(keysize)
    private_key = RSA.import_key(keypair.export_key())
    public_key = RSA.import_key(keypair.publickey().export_key())
    return (public_key, private_key)

def main():
    AES_key = get_random_bytes(32)

    public_key, private_key = create_keypair()
    decrypted_key = encrypt_and_decrypt_challenge(public_key, private_key, AES_key)

    if decrypted_key == AES_key:
        print("Correct RSA!")
    else:
        print("Please try again")

if __name__ == '__main__':
    main()