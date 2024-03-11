# Dictionary
capitals = {
    "Hungary": "Budapest",
    "Greece": "Athens",
    "Spain": "Madrid",
    "Germany": "Berlin",
    "Russia": "Moscow"
}

capitals.update({"Italy": "Rome"})
capitals.pop("Russia")

print(capitals["Spain"])
print(capitals.get("Germany"))
print(capitals.keys())
print(capitals.values())
print(capitals.items())
print("------------")

for key, value in capitals.items():
    print(key + " - " + value)
