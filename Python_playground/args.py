# Args
def addition(*args):
    sum = 0
    for i in args:
        sum += i
    return sum


print(addition(1, 2, 3, 4, 5))
