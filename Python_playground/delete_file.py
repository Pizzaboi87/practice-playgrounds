# Delete a file
import os

path = "test.txt"

try:
    os.remove(path)
except FileNotFoundError:
    print(path + " was not found.")
except PermissionError:
    print("You don't have permission.")
else:
    print(path + " was successfully deleted.")
