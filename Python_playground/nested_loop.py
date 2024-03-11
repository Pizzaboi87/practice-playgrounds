# Nested loop
rows = int(input("How many rows?: "))
cols = int(input("How many cols?: "))
symbol = input("Enter a symbol to use: ")

for i in range(rows):
    for j in range(cols):
        print(symbol, end="")
    print()
