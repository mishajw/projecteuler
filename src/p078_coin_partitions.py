from functools import lru_cache
from itertools import count

@lru_cache(maxsize=None)
def f(x, lim):
    if x == 1 or x == 0:
        return 1
    return sum(
            f(x - i, min(lim, i))
            for i in range(1, min(lim + 1, x + 1)))

for i in count():
    value = f(i, i)
    if value % int(1e6) == 0:
        print(i, value)
        break

