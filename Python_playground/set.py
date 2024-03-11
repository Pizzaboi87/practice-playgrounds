# Set
utensils = {"knife", "fork", "spoon"}
dishes = {"bowl", "plate", "cup", "knife"}

utensils.add("napkin")
utensils.remove("fork")

dinner_table = utensils.union(dishes)

for i in dinner_table:
    print(i)

print(utensils.intersection(dishes))
