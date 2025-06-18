from Cryptodome.Cipher import AES
from Cryptodome.Util.strxor import strxor
import binascii

def __increment_counter(counter):
    if counter == b'\xff'*16: # We need to to roll over instead of continuing to add
        return b'\x00'*16
    counter_as_int = int.from_bytes(counter, byteorder='big')
    counter_as_int += 1
    return counter_as_int.to_bytes(len(counter),byteorder='big')

def __get_block_length(message_length):
    block_length = message_length//16
    if message_length % 16 != 0:
        block_length += 1 # this accounts for a partial block because the // operator truncates
    return block_length

def __pad_message(message):
    if len(message) % 16 == 0:
        padding = 0
    else:
        padding = (1 + (len(message)//16))*16 - len(message)
    padded_message = message + b"\x00"*padding
    return padded_message



def AES_encrypt(key, block):
    cipher = AES.new(key, mode=AES.MODE_ECB)
    return cipher.encrypt(block)

def CTR_encrypt(key, iv, message):
    # a few initialization steps
    block_length = __get_block_length(len(message))
    encrypted_message = b''

    for i in range(block_length):
        message_block = message[i*16:(i+1)*16] # get the current block in the message
        key_stream = AES_encrypt(key, iv) # get the current key_stream for this block; note, it has nothing to do with the message
        encrypted_message += strxor(key_stream, message_block) # here is where the encryption actually happens with XOR
        iv = __increment_counter(iv) # we need to increase the iv/counter for counter mode (otherwise we just have a fancier ECB)
    return encrypted_message

def main():
    key = b'00000000000000000000000000000000' # needs to be 16, 24, or 32 bytes
    iv = b'1234567890abcdef' # needs to be 16 bytes; I chose to use a single IV, but Pycryptodome has separate IV and nonce for counter mode; can make them semantically the same

    message = b'Here we are demonstrating counter mode.  We can see that the message is only used at the end in an XOR operation.  Instead, we see the IV get encrypted in each block.'
    print(f"Message: {message}\n")

    padded_message = __pad_message(message) # padding message to the next 16 bytes; padding with null bytes
    encrypted_message = CTR_encrypt(key, iv, padded_message)
    print(f"Encrypted Message: {binascii.hexlify(encrypted_message)}\n")

    decrypted_message = CTR_encrypt(key, iv, encrypted_message) # decryption is the same as encryption because of the properties of XOR
    print(f"Decrypted Message: {decrypted_message}")

if __name__ == "__main__":
    main()