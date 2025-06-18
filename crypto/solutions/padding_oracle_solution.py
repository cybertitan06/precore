import socket
import binascii
from Cryptodome.Util.strxor import strxor

# this function returns the bytestring corresponding to the desired PKCS#7 padding for the specified index we are trying to solve for
# idx 15 pads with b"\x01" at the end
# idx 14 pads with b"\x02\x02"
# idx 13 pads with b"\x03\x03\x03"
# ...
# idx 01 pads with b"\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15\x15"
# idx 00 pads with a whole block of b"\x10" bytes 
def get_desired_padding(idx):
    temp = b'\x00'*idx
    temp += int.to_bytes(16-idx, 1, 'big')*(16-idx)
    return temp

# this function works to get us the correct intermediate value from AES decryption using the padding oracle
def loop_for_padding(s, ct, intermediate_val, idx):
    for i in range(256):
        # These lines are probably the core of the padding oracle attack to decrypt a byte at a time
        iv = b"\x00"*(idx) + int.to_bytes(i,1,'big') + b"\x00"*(15-idx) # incorporates our current guess to try to decrypt the byte; iterating through all values for i will eventually get us the correct guess
        current_intermediate_guess = strxor(iv, binascii.unhexlify(intermediate_val)) # incorporates our current byte guess with the current intermediate value we know
        custom_iv = strxor(current_intermediate_guess, get_desired_padding(idx)) # alters our current guess according to the padding we want to have when the value gets decrypted to make the XOR correct

        message = binascii.hexlify(custom_iv) + ct # prep the message we want to send
        s.send(message) # send the message

        # check if the decrypted message had the correct padding; if so we are done with this byte
        rec = s.recv(255)
        if rec == b'OK':
            break

    return strxor(custom_iv, get_desired_padding(idx))

def main():
    plaintext = b'' # accumulator for decryption
    # Code to set up networking
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0) as s:
        s.connect(("localhost", 33333))

        # get the ciphertext we need to decrypt; students could also hard code this as long as they handle networking properly
        ciphertext = s.recv(255)
        print(f"Ciphertext: {ciphertext}") # ciphertext is hexlified for easy printing

        # Do the decryption with the padding oracle
        num_blocks = len(ciphertext)//32 - 1 # get number of blocks; subtract 1 to remove IV

        # iterate over all blocks we want to decrypt
        for block in range(num_blocks):
            # "intermediate_value" will store the direct output from running the ciphertext block through the AES decrypt function without considering the block cipher mode
            # figuring out what these bytes should be is the core behind the padding oracle attack because we already have the previous ciphertext block/IV with which to XOR it for decryption
            intermediate_value = b'0'*32

            # iterate over all bytes in the block; we decrypt the block from right to left
            for idx in range(15,-1,-1):
                # loop for padding function gets us the correct intermediate value for the desired index
                intermediate_value = binascii.hexlify(loop_for_padding(s, ciphertext[32*(block+1):(32*(block+1)) + 32], intermediate_value,idx))
            
            # XOR the intermediate value we found with the ciphertext block preceding the one we are looking at to finalize decryption
            plaintext += strxor(binascii.unhexlify(intermediate_value), binascii.unhexlify(ciphertext[32*block:32*block + 32]))

    #print our decrypted ciphertext/original plaintext message
    print(plaintext)

if __name__ == "__main__":
    main()
