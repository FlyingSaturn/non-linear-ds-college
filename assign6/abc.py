with open('input.txt', 'r') as file:
    numbers_list = [int(num) for num in file.read().split()]

for a in numbers_list:
    print(a)
