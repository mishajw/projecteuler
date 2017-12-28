from itertools import product

print(next(a * b * (1000 - a - b)
    for a, b in product(range(1, 1001), repeat=2) if a**2 + b**2 == (1000 - a - b)**2))

