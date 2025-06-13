from Cryptodome.PublicKey import ECC
from Cryptodome.Signature import DSS
from Cryptodome.Random import get_random_bytes
from Cryptodome.Hash import SHA3_384

def create_keypair():
    curve = 'p384' # fill in appropriate RSA keysize here
    return __create_keypair(curve) # do not edit this line

def sign(key, message):
    sig_alg = DSS.new(key, 'fips-186-3')
    sha_obj = SHA3_384.new(message)
    return sig_alg.sign(sha_obj)

def verify(key, message, sig):
    sig_alg = DSS.new(key, 'fips-186-3')
    sha_obj = SHA3_384.new()
    sha_obj.update(message)
    sig_alg.verify(sha_obj, sig)

def signature_challenge(public_key, private_key, data):
    signature = sign(private_key, data)
    verify(public_key, data, signature)
    

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def __create_keypair(curve):
    keypair = ECC.generate(curve=curve)
    private_key = ECC.import_key(keypair.export_key(format='PEM'))
    public_key = keypair.public_key()
    return (public_key, private_key)

def main():
    AES_key = get_random_bytes(32)

    public_key, private_key = create_keypair()
    try:
        signature_challenge(public_key, private_key, AES_key)
    except:
        print("Failed to verify\nPlease try again")
        return
    print("Congratulations!")

if __name__ == '__main__':
    main()