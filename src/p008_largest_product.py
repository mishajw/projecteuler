from functools import reduce

LENGTH = 13

def get_values():
    with open("inputs/p008_largest_product.txt") as f:
        s = "".join(l.strip() for l in f)
        s = list(map(int, s))
        for i in range(len(s) - LENGTH - 1):
            yield s[i:i + LENGTH]

print(max(reduce(lambda x, y: x * y, xs) for xs in get_values()))

