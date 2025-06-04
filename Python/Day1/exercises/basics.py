import random
import base64

# 1. Assign an integer value to the variable bottles and print it
bottles = 5
print(f"Bottles value is {bottles}\n")

# 2. Multipart.

# 2.1 Write some code to determine the number of seconds in an hour.
print("\nExercise 2 output ===============================================") 
hour = 1
minutes = 60
seconds = 60
seconds_in_hour = hour * minutes * seconds
seconds_in_a_day = 24 * minutes * seconds
print(f"The number of seconds in {hour} hour(s) is {seconds_in_hour} seconds")

# 2.2 Assign that value to a variable. 

# 2.3 Using that variable, determine how many seconds are in a day.

# 2.4 Save the result from 2.3 to a variable. 

# 2.5 Divide the number of seconds in a day by the number of seconds per hour using both floating point and integer division. Check to see if they are the same.
int_result = int(seconds_in_a_day / seconds_in_hour)
float_result = float(seconds_in_a_day / seconds_in_hour)

print(f"Int: {int_result}\nFloat: {float_result}")

# 3. Multipart.
print("\nExercise 3 output ===============================================")
# 3.1 Assign a number between 1 and 10 to a variable secret. 
secret = random.randint(1,10)
print(f"Secret number is {secret}")
# 3.2 Assign another number between 1 and to to a variable guess. 
guess = random.randint(1,10)
print(f"Guess is {guess}")
# 3.3 Write conditional code to print "too high", "too low", and "correct" depending on whether guess is higher, lower, or equal to secret.
if (guess < secret):
    print("Too low")
elif (guess > secret):
    print("Too high")
else:
    print ("You got it!")

# 4. Assign True/False to `small` and `green`. Write an if/else to print which of those match "cherry", "pea", "watermelon", or "pumpkin".
print("\nExercise 4 output ===============================================")

small = True
green = True

if (small and green):
    print("Peas are small and green")
elif(small and not(green)):
    print("Cherries are small and not green")
elif(not(small) and green):
    print("Watermelons are not small and green")
elif(not(small) and not(green)):
    print("Pumpkins are not green and not small")

# 5. Capitalize the word starting with `c`. ```phrase  = "The farmer said:\n How now brown cow.\n Where are you going?"```
print("\nExercise 5 output ===============================================")

phrase = "The farmer said:\n How now brown cow.\n Where are you going?"

split_phrase = phrase.split()
specific_word = split_phrase[6]
capitalize_word = specific_word.capitalize()
split_phrase[6] = capitalize_word
rejoined_phrase = " ".join(split_phrase)

print(rejoined_phrase)

# 6. Print the following with in the form Q: question\n A: answer
print("\nExercise 6 output ===============================================")

questions = [
    "We don't serve strings around here. Are you a string?",
    "What is said on Father's Day in the forest?",
    "What makes the sound 'Sis! Boom! Bah!'?"
]
answers = [
    "An exploding sheep.",
    "No, I'm a frayed knot.",
    "'Pop!' goes the weasel."
]

for i in range(3):
    print(f"Q: {questions[i]}\n A: {answers[i]}")

# 7. Write the following using old style formatting. Substitute in "know", "though", "here", "snow".
print("\nExercise 7 output ===============================================")

# 8. Multipart.
print("\nExercise 8 output ===============================================")

# 8.1 Save the following as letter

letter = """Dear {salutation} {name},
 
Thank you for your letter. We are sorry that our {product}
{verbed} in your {room}. Please note that it should never
be used in a {room}, especially near any {animals}.
 
Send us your receipt and {amount} for shipping and handling.
We will send you another {product} that, in our tests,
is {percent}% less likely to have {verbed}.
 
Thank you for your support.
 
Sincerely,
{spokesman}
{job_title} """

d = {"salutation":"Mr.", "name":"Austin", "product":"Switch", "verbed":"died", "room":"barn", "animals":"stallions", "amount": "350 dollars", "percent": 69, "spokesman":"Diddy", "job_title":"Customer Support"}
# 8.2 Assign the letter the values of your choosing using `.format()`.  
letter_format_formatted = letter.format(**d)

# 8.3 Assign the letter the values of your choosing using f strings.  
letter_fstrings_formatted = print(f"""Dear {d['salutation']} {d['name']},
 
Thank you for your letter. We are sorry that our {d['product']}
{d['verbed']} in your {d['room']}. Please note that it should never
be used in a {d['room']}, especially near any {d['animals']}.
 
Send us your receipt and {d['amount']} for shipping and handling.
We will send you another {d['product']} that, in our tests,
is {d['percent']}% less likely to have {d['verbed']}.
 
Thank you for your support.
 
Sincerely,
{d['spokesman']}
{d['job_title']}""")

print(letter_fstrings_formatted)

# 9. Use a for loop to print the values of the list [3, 2, 1, 0]. 
print("\nExercise 9 output ===============================================")

ex_list = [3, 2, 1, 0]
for i in ex_list:
    print(i)

# 10. Use your code from 2, a `while` loop, and `input()` the have the user guess the secret number.
print("\nExercise 10 output ===============================================")

secret = random.randint(1,10)
print(f"Secret number is: {secret}")
while(False):
    guess = input("Please enter a guess: ")
    if (int(guess) < secret):
        print("Too low")
    elif (int(guess) > secret):
        print("Too high")
    else:
        print ("You got it!")
        break

# 11. Get a number from a user, use a binary search algorithm to determine what the number is in the fewest number of steps.
# The program should pring iteration of the search, and whether the current number was too high, low, or if it found the number.


# 12. Get a password from the user (or use a sample string) and determine whether it is secure. It should contain at least 1 uppercase letter,
# 1 lowercase letter, 1 number, and 1 special character. It should be at least 14 characters long, and have no more than 3 repeat elements 
# (aka no 4 letters in a row, 4 numbers in a row, etc...)


# 13. Decode the following base64 encoded message using Python dGhlIGNha2UgaXMgYSBsaWU=
encoded_message = 'dGhlIGNha2UgaXMgYSBsaWU='

decoded_message = base64.b64decode(encoded_message).decode('utf-8')

print("Decoded text:", decoded_message)