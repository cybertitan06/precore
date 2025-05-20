from Crypto.Random import random
from Crypto.Hash import SHA3_512

def main():
    num_passwords = 5000
    username = b"johnb"
    passes = []
    with open("rockyou.txt", "rb") as r:
        with open("rockyou_ACE.txt", "wb") as a:
            for i in range(num_passwords):
                password = r.readline()
                passes.append(password.strip())
                a.write(password)

    password = random.choice(passes)
    hash_obj = SHA3_512.new()
    hash_obj.update(password)
    print(password)
    with open("lab04_hash.txt", "w") as c:
        c.write(username.decode() + ":" + hash_obj.hexdigest())

    password = random.choice(passes)
    
    hash_obj = SHA3_512.new()
    hash_obj.update(username + password)
    with open("lab04_saltedhash.txt", "w") as c:
        c.write(username.decode() + ":" + hash_obj.hexdigest())


if __name__ == '__main__':
    main()