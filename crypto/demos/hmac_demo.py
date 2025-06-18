from Cryptodome.Hash import HMAC, SHA256
from Cryptodome.Util.strxor import strxor
import sys

def real_hmac(key, message):
    h = HMAC.new(key, digestmod=SHA256)
    h.update(message)
    return (h.hexdigest())

def custom_hmac(key, message):
    if len(key) > 64: # typical key lengths in practice are 32 bytes, but these can really be any length; we need to truncate if larger than 64 bytes (at least for SHA256)
        key_hasher = SHA256.new(key)
        key = key_hasher.digest()

    key += b"\x00"*(64 - len(key))
    ipad = b"\x36"*len(key)
    opad = b"\x5c"*len(key)

    ipad_key = strxor(ipad, key)
    opad_key = strxor(opad, key)

    internal_sha = SHA256.new(ipad_key + message).digest()
    external_sha = SHA256.new(opad_key + internal_sha).hexdigest()

    return external_sha


def main():
    key = sys.argv[1].encode() # typical key lengths in practice are 32 bytes, but these can really be any length
    message = sys.argv[2].encode() # can be any length

    print(f"Message: {message}")
    print(f"Key: {key}")
    real = real_hmac(key,message)
    custom = custom_hmac(key, message)

    print(real)
    print(custom)

if __name__ == "__main__":
    main()
