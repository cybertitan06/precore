##############################################################################################################
# This lab demonstrates the basic properties of a mathematical group
# A group requires a set of elements and an operation that meet certain properties
# For this code, the set of elements is numbers from 0 through a chosen value
# The operation in this code is addition mod the chosen value
# Group properties:
#   Identity element is 0
#   Addition is commutative and associative
##############################################################################################################


import math

def check_coprime(p, g):
    return p == (p//g)*g

def brute_force_primality_check(n):
    for i in range(2, int(math.sqrt(n))):
        if n == (n//i)*i:
            return False
    return True

def main():
    p = abs(int(input("Please enter a number to define your group (primes work best): ")))
    print(f"Using additive group of numbers from 0 to {p}\n")
    if not brute_force_primality_check(p):
        print(f"{p} is not prime! Your generator might produce a subgroup!\n")
    generator = int(input("Please enter a number as a generator (not 0): ")) % p

    if generator == 0:
        print("Zero is not a valid generator because it is the identity element")
        return

    if check_coprime(p, generator):
        print("Values are not coprime! We get to see a sub-group!\n")
    else:
        print("")

    val = generator
    looped = False
    group_order = 0
    while not looped:
        group_order += 1
        print(f"Value is: {val}")
        val = (val + generator) % p
        if val == generator: looped = True
    
    print(f"At end, val is {val}, and we found order size {group_order} out of maximum size {p}")

if __name__ == "__main__":
    main()