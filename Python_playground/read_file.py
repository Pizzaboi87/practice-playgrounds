# Read a file
path_to_read = "./test.txt"

try:
    with open(path_to_read) as file:
        print(file.read())
except FileNotFoundError:
    print("The file was not found.")
