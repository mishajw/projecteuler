import itertools
from peutil import get_divisors

for i in itertools.count():
    i_divisors = get_divisors(i)
    j_divisors = get_divisors(i + 1)

    ij_divisors = set(a * b for a, b in itertools.product(i_divisors, j_divisors))
    tri_divisors = set(x // 2 for x in ij_divisors if x % 2 == 0)
    if len(tri_divisors) > 500:
        print(i * (i + 1) // 2)
        break

