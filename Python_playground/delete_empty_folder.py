# Delete an empty folder
import os

empty_folder = "empty_folder"

try:
    os.rmdir(empty_folder)
except FileNotFoundError:
    print(empty_folder + " was not found.")
except PermissionError:
    print("You don't have permission.")
except OSError:
    print("The folder is not empty, you can't use this function.")
else:
    print(empty_folder + " was successfully deleted.")
