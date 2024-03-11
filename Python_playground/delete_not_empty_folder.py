# Delete a folder with data
import shutil

folder_with_data = "folder_with_data"

try:
    shutil.rmtree(folder_with_data)
except FileNotFoundError:
    print(folder_with_data + " was not found.")
except PermissionError:
    print("You don't have permission.")
except OSError:
    print("The folder is not empty, you can't use this function.")
else:
    print(folder_with_data + " was successfully deleted.")
