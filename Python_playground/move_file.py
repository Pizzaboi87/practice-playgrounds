# Move a file
import os

source = "test.txt"
destination = "copy/copy.txt"

try:
    if os.path.exists(destination):
        print(source + " is already there.")
    else:
        os.replace(source, destination)
        print(source + " was moved successfully.")
except FileNotFoundError:
    print(source + " was not found.")
