import itertools
import peutil

FIND = 50000000
PRIME_LIMIT = 100000

def f(a, b, c):
    return a**2 + b**3 + c**4

primes = peutil.get_primes(PRIME_LIMIT)
for i, p in enumerate(primes):
    if f(p, primes[0], primes[0]) > FIND:
        primes = primes[:i + 1]
        break

possible = []
for a in primes:
    a_pos_len = len(possible)
    for b in primes:
        b_pos_len = len(possible)
        for c in primes:
            val = f(a, b, c)
            if val > FIND:
                break
            possible.append(val)
        if len(possible) == b_pos_len:
            break
    if len(possible) == a_pos_len:
        break

print(len(set(p for p in possible)))

