import sys

lengths = {}

def set_length(n):
    if n in lengths:
        return lengths[n]

    if n == 1:
        length = 1
    elif n % 2 == 0:
        length = set_length(n // 2) + 1
    else:
        length = set_length(3 * n + 1) + 1

    lengths[n] = length
    return length

print(max((i for i in range(1, 1000000)), key=set_length))

