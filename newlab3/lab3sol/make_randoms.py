import sys
import random

# python make_randoms.py <output_file> <# of integers>

with open(sys.argv[1], "w") as output:
    arr = [i for i in range(int(sys.argv[2]))]
    random.shuffle(arr)
    for number in arr:
        output.write(str(number)+"\n")
