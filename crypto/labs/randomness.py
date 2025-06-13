from Cryptodome.Cipher import AES
import random
import binascii
import asyncio

key = b"East is the best"

def encrypt_data(data):
    random.seed(0)
    IV = random.randbytes(8)
    data += b"\x00"*(16 - (len(data) % 16))
    cipher = AES.new(key, AES.MODE_CTR, nonce=IV)
    print(f"NONCE: {binascii.hexlify(cipher.nonce)}");
    encrypted_message = cipher.encrypt(data)
    challenge = binascii.hexlify(encrypted_message)
    return challenge

async def handle_client(reader, writer):
    challenge_message = b"May the great Virtual Machine purge of 2016 be forever remembered."
    challenge = encrypt_data(challenge_message)
    writer.write(challenge + b"\n")
    await writer.drain()
    plaintext = (await reader.read(255))
    ciphertext = encrypt_data(plaintext)
    writer.write(ciphertext + b"\n")
    await writer.drain()
    writer.close()

async def run_server():
    server = await asyncio.start_server(handle_client, "0.0.0.0", 22222)
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(run_server())
