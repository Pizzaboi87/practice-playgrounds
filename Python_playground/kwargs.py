# Kwargs
def hello(**kwargs):
    print("Hello", end=" ")
    for key, value in kwargs.items():
        print(value, end=" ")


hello(title="Ms.", first_name="Rahel",
      middle_name="Anna", last_name="Temesvari")
