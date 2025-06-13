
from Cryptodome.Protocol import DH, KDF
from Cryptodome.PublicKey import ECC
from Cryptodome.Random import get_random_bytes
from Cryptodome.Hash import SHA3_256
import binascii

def call_derives(alice_keypair, bob_keypair):
    a_priv =    # set this variable correctly
    a_pub =     # set this variable correctly
    b_priv =    # set this variable correctly
    b_pub =     # set this variable correctly

    a_shared_secret = alice_derive(_, _)    # set the arguments to this function correctly
    b_shared_secret = bob_derive(_, _)      # set the arguments to this function correctly

    display_shared_secret(a_shared_secret, "Alice")
    display_shared_secret(b_shared_secret, "Bob")

    return (a_shared_secret, b_shared_secret)

def alice_derive(alice_priv, bob_pub):
    shared_secret = DH.key_agreement(eph_priv=, eph_pub=, kdf=__kdf) # set the arguments appropriately here
    return shared_secret

def bob_derive(bob_priv, alice_pub):
    shared_secret = DH.key_agreement(eph_priv=, eph_pub=, kdf=__kdf) # set the arguments appropriately here
    return shared_secret

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def display_shared_secret(keys, name):
    aes_key = binascii.hexlify(keys[0])
    mac_key = binascii.hexlify(keys[1])
    
    print(f"{name}'s shared AES key: {aes_key}\n{name}'s shared MAC key: {mac_key}")

def create_keypair():
    curve = 'Curve25519'
    return __create_keypair(curve)

def __kdf(ikm):
    return KDF.HKDF(ikm, key_len=32, hashmod=SHA3_256, salt=b'', num_keys=2, context=b"my_own_diffie_hellman")

def __create_keypair(curve):
    keypair = ECC.generate(curve=curve)
    private_key = ECC.import_key(keypair.export_key(format='PEM'))
    public_key = keypair.public_key()
    return (public_key, private_key)

def main():
    alice_keypair = create_keypair()
    bob_keypair = create_keypair()

    assert(alice_keypair != bob_keypair)

    a_shared_secret, b_shared_secret = call_derives(alice_keypair, bob_keypair)
    if a_shared_secret == b_shared_secret:
        print("Correct use of Diffie-Hellman!")
    else:
        print("Diffie-Hellman is incorrect")


if __name__ == "__main__":
    main()
