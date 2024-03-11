# Write a file
text = "This is a new example test.\nThis will be in the new file,\nHopefully\n"

with open('new_file.txt', 'w') as file:
    file.write(text)

append_text = "\nThis text will follow the previous one."

with open('new_file.txt', 'a') as file:
    file.write(append_text)
