from Cryptodome.Random import get_random_bytes
import binascii

class RandomOracle():
    def __init__(self, output_size=160):
        self.table = {}
        if output_size % 8 != 0:
            raise ValueError("output_size of RandomOracle must be byte aligned (a multuiple of 8)")
        self.output_size = output_size//8

    def query(self, s):
        if s in self.table.keys():
            return self.table[s]
        else:
            self.table[s] = get_random_bytes(self.output_size)
            return self.table[s]

def main():
    ro = RandomOracle(256)

    messages = ["Hello", "World", "Helloworld", "Hello", "ASDF"]

    for message in messages:
        print(f"Message: {message}")
        print(f"Hash: {binascii.hexlify(ro.query(message))}")

if __name__ == "__main__":
    main()
