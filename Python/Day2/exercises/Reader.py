# #file operations with open
#https://docs.python.org/3/library/functions.html
# open() Parameters
#     file - path-like object (representing a file system path)
#     mode (optional) - mode while opening a file. If not provided, it defaults to 'r' (open for reading in text mode). Available file modes are:	
#     					Mode
#     						Description    				
#     					'r'
#     						Open a file for reading. (default)
#     					'w'
#     						Open a file for writing. Creates a new file if it does not exist or truncates the file if it exists.
#     					'x'
#     						Open a file for exclusive creation. If the file already exists, the operation fails.
#     					'a'
#     						Open for appending at the end of the file without truncating it. Creates a new file if it does not exist.
#     					't'
#     						Open in text mode. (default)
#     					'b'
#     						Open in binary mode.
#     					'+'
#     						Open a file for updating (reading and writing)
 
def display_menu():
    print("WHat do you want to do")
    print("1. Read")
    print("2. Write")
    print("3. Append")
    print("4. Remove")
    print("5. Exit")

def read_file(file_path):
    try:
        with open(file_path, 'r') as file:
            contents = file.read()
            print("\nFile Contents:\n")
            print(contents)
            file.close()
    except FileNotFoundError:
        print(f"The file {file_path} does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

def write_file(file_path, content):
    try:
        with open(file_path, 'w') as file:
            file.write(content)
        print(f"This content overwrote anything in the file {file_path}.")
        file.close()
    except Exception as e:
        print(f"An error occurred: {e}")

def append_file(file_path, content):
    try:
        with open(file_path, 'a') as file:
            file.write(content)
        print(f"Content appended to {file_path}.")
        file.close()        
    except Exception as e:
        print(f"An error occurred: {e}")

def remove_lines(file_path, word):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()

        with open(file_path, 'w+') as file:
            for line in lines:
                if word not in line:
                    file.write(line)
            contents = file.read()
            print("\nPRINT New File Contents??:\n\n\n")#this doed not work because the + truncates the file
            print(contents)
        print(f"Lines containing '{word}' removed in {file_path}.")
    except FileNotFoundError:
        print(f"The file {file_path} does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

def main():
    while True:
        display_menu()
        choice = input("Enter your choice (1-5): ")
        if choice == '1':
            file_path = input("Enter the path to file: ")
            read_file(file_path)
        elif choice == '2':
            file_path = input("Enter the path to file: ")
            content = input("Enter the content to write: ")
            write_file(file_path, content)
        elif choice == '3':
            file_path = input("Enter the path to file: ")
            content = input("Enter the content to append: ")
            append_file(file_path, content)
        elif choice == '4':
            file_path = input("Enter the path to file: ")
            word = input("Enter the keyword to remove lines containing it: ")
            remove_lines(file_path, word)
        elif choice =='5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")
        print("\n")

if __name__ == "__main__":
    main()
