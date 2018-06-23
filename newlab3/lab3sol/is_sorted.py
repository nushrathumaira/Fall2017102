import sys

# python is_sorted.py <input_file>

with open(sys.argv[1], "r") as numbers:
    arr = []
    for line in numbers.readlines():
        arr.append(int(line))

    if all(a <= b for a,b in zip(arr[:-1], arr[1:])):
        print("List of " + str(len(arr)) + " integers is sorted!\n")
    else:
        print("List is not sorted...\n")
