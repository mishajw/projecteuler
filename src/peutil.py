from typing import List
import math

def get_divisors_iter(n: int) -> List[int]:
    for i in range(1, n // 2 + 1):
        if n % i == 0:
            yield i
    yield n

def get_divisors(n: int) -> List[int]:
    return list(get_divisors_iter(n))

def get_prime_sieve(n: int) -> List[bool]:
    sieve = [True] * n
    sieve[0] = False
    sieve[1] = False

    for i in range(2, n // 2 + 1):
        for j in range(i + i, n, i):
            sieve[j] = False

    return sieve

def get_primes(n: int) -> List[int]:
    sieve = get_prime_sieve(n)
    return [i for i, p in enumerate(sieve) if p]

