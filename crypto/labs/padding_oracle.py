import asyncio
from Cryptodome.Cipher import AES
from Cryptodome.Random import get_random_bytes
import binascii
from Cryptodome.Util.Padding import pad, unpad

key = b"EAST IS THE BEST"

def encrypt_message(message):
    IV = get_random_bytes(16)
    cipher = AES.new(key, AES.MODE_CBC, IV)
    ct = cipher.encrypt(pad(message, AES.block_size))
    #print(binascii.hexlify(cipher.iv) + binascii.hexlify(ct))

def decrypt_data(data):
    IV = binascii.unhexlify(data[0:32])
    ct = binascii.unhexlify(data[32:])
    cipher = AES.new(key, AES.MODE_CBC, IV)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    print(pt)

async def handle_client(reader, writer):
    writer.write(b"97602bdde28a568960dec2a3655453559b0e445528c5c545fd96b1fe7e81ba99e422ceb94bdad46f8685ca9794b054e306368043e11c23ae9f08211954aa1cc46e63d14b6e5ee5ff2bf052a55e41573d8fa36ca3d0e0bc2a15f44333890c1dc2\n")
    data = await reader.read(255)
    while data.strip() != "quit":
        try:
            decrypt_data(data.strip())
            writer.write(b"OK")
        except:
            writer.write(b"FAIL\n")
        await writer.drain()
        data = await reader.read(255)

async def run_server():
    server = await asyncio.start_server(handle_client, "0.0.0.0", 33333)
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(run_server())
