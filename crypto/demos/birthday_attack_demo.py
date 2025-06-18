from Cryptodome.Random.random import randint

import sys

def run_experiment(num_people):
    birthdays = set()
    for i in range(num_people):
        birthdays.add(randint(0,364))

    # use properties of sets to check if we have a collision
    # if we have a collision, the size of the set will be smaller than the number of people
    if len(birthdays) == num_people:
        return 0
    return 1

def main():
    if len(sys.argv) == 1:
        num_people = 23
    else:
        try:
            num_people = int(sys.argv[1])
            if num_people < 0:
                raise ValueError("Need a positive integer")
        except Exception as e:
            print(f"{sys.argv[1]} is not a valid number of people.  Please enter a positive integer")
            return
    num_experiments = 100000

    print(f"Running {num_experiments} experiments for {num_people} people.")
    collisions = 0
    for i in range(num_experiments):
        collisions += run_experiment(num_people)
    print(f"{collisions} collisions out of {num_experiments} experiments")

if __name__ == "__main__":
    main()
