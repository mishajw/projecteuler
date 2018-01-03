from functools import lru_cache

@lru_cache(maxsize=None)
def f(x, lim):
    if x == 1 or x == 0:
        return 1
    return sum(
            f(x - i, min(lim, i))
            for i in range(1, min(lim + 1, x + 1)))
print(f(100, 99))

