from Cryptodome.Cipher import AES
from Cryptodome.PublicKey import RSA
from Cryptodome.Cipher import PKCS1_OAEP
from Cryptodome.Random import get_random_bytes
import timeit

# Making these globals to make sure that all functions can access them
# Avoids including setup time in the functions we want to time
message = get_random_bytes(32)

AES_key = get_random_bytes(32)
RSA_keypair = RSA.generate(1024)
private_key = RSA_keypair
public_key = RSA_keypair.public_key()

AES_cipher = AES.new(AES_key, AES.MODE_CBC, iv=b'0000000000000000')
AES_cipher_decrypt = AES.new(AES_key, AES.MODE_CBC, iv=b'0000000000000000')
RSA_cipher = PKCS1_OAEP.new(RSA_keypair)

RSA_encrypted_message = RSA_cipher.encrypt(message)
AES_encrypted_message = AES_cipher.encrypt(message)

def RSA_encrypt():
    RSA_cipher.encrypt(message)

def RSA_decrypt():
    RSA_cipher.decrypt(RSA_encrypted_message)

def AES_encrypt():
    AES_cipher.encrypt(message)

def AES_decrypt():
    AES_cipher_decrypt.decrypt(AES_encrypted_message)

def main():
    num_runs = 10000
    RSA_encrypt_time = timeit.timeit(RSA_encrypt, number=num_runs)*1000000/num_runs
    print("Done RSA Encrypt")
    RSA_decrypt_time = timeit.timeit(RSA_decrypt, number=num_runs)*1000000/num_runs
    print("Done RSA Decrypt")

    AES_encrypt_time = timeit.timeit(AES_encrypt, number=num_runs)*1000000/num_runs
    print("Done AES Encrypt")
    AES_decrypt_time = timeit.timeit(AES_decrypt, number=num_runs)*1000000/num_runs
    print("Done AES Decrypt")

    print(f"Average RSA encrypt time:\t{RSA_encrypt_time} microseconds")
    print(f"Average RSA decrypt time:\t{RSA_decrypt_time} microseconds")
    print(f"Average AES encrypt time:\t{AES_encrypt_time} microseconds")
    print(f"Average AES decrypt time:\t{AES_decrypt_time} microseconds")

if __name__ == "__main__":
    main()
