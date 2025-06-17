from Cryptodome.Hash import SHA3_512
import binascii


#####################################################################################
#ONLY EDIT THIS FUNCTION
#Hint: Brute force is always an option
def crack_password(hash, wordlist):
    for word in wordlist:
        word_hash = SHA3_512.new(word)
        if word_hash.hexdigest().encode() == hash:
            return word

###############################################################################################
# DO NOT EDIT BELOW
###############################################################################################

def read_passes():
    passes = []
    with open("./resources/rockyou_ACE.txt", "rb") as r:
        for line in r.readlines():
            passes.append(line.strip())
    return passes

def get_username_and_hash():
    with open("./resources/lab04_hash.txt", "rb") as h:
        line = h.readline()
    username = line.split(b":")[0]
    hash = line.split(b":")[1]
    return (username, hash)

def test_password(password, hash):
    hash_obj = SHA3_512.new()
    hash_obj.update(password)
    if hash == hash_obj.hexdigest().encode():
        print(f"Found correct password: {password}")

def main():
    wordlist = read_passes()
    username, hash = get_username_and_hash()
    print(f"Username: {username}")
    cracked_password = crack_password(hash, wordlist)
    test_password(cracked_password, hash)

if __name__ == "__main__":
    main()
