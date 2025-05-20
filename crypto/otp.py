from Crypto import Random
import binascii

real_message  = b"Competence, Courage, Commitment, Compassion"
fake_message1 = b"No excuses, No extensions, No exceptions..."
fake_message2 = b"Valinor will commence the attack at dawn..."
fake_message3 = b"Malazan has committed to aiding Halcyon...."

ciphertext = Random.get_random_bytes(len(real_message))

crypt = (lambda bytes, key: (a ^ b for a, b in zip(bytes, key)))

real_key = bytes(crypt(real_message, ciphertext))
decrypted = bytes(crypt(ciphertext, real_key))

fake_key1 = bytes(crypt(fake_message1, ciphertext))
fake_key2 = bytes(crypt(fake_message2, ciphertext))
fake_key3 = bytes(crypt(fake_message3, ciphertext))

print(f"Ciphertext: {binascii.hexlify(ciphertext)}")
print(f"Real Message: {real_message}")
print(f"Real Key: {binascii.hexlify(real_key)}")
print(f"Fake Message: {fake_message1}")
print(f"Fake Key: {binascii.hexlify(fake_key1)}")
print(f"Fake Message: {fake_message2}")
print(f"Fake Key: {binascii.hexlify(fake_key2)}")
print(f"Fake Message: {fake_message3}")
print(f"Fake Key: {binascii.hexlify(fake_key3)}")