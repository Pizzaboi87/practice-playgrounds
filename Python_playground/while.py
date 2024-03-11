# 02 Example
age = None

while not age:
    age = input("\nHow old are you?: ")
age = int(age)

if age == 100:
    print("Wow! You are a century years old.")
elif age > 100:
    print("Hmm... Are you in the Guiness World Records as well?")
elif age >= 18:
    print("Ok, so you are an adult.")
elif age < 0:
    print("Hmm... It seems you haven't been born yet.")
else:
    print("Ok, then you are a child.")
