from typing import List
import math

def get_divisors_iter(n: int) -> List[int]:
    for i in range(1, n // 2 + 1):
        if n % i == 0:
            yield i
    yield n

def get_divisors(n: int) -> List[int]:
    return list(get_divisors_iter(n))

