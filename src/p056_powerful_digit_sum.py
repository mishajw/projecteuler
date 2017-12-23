from itertools import product
print(max(sum(map(int, str(i**j))) for i, j in product(range(1, 101), repeat=2)))

