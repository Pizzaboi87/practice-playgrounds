# 03 Example
temp = None

while not temp:
    temp = input("\nWhat is temperature?: ")
temp = int(temp)

if (temp < -30 or temp > 50):
    print("Are you still alive?")
elif not (temp >= 0 and temp <= 30):
    print("The weather is bad today. :(")
else:
    print("The weather is good today. :)")
