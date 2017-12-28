import itertools

LIMIT = 28123

abundant = [1] * LIMIT
for i in range(2, LIMIT):
    for x in range(i + i, LIMIT, i):
        abundant[x] += i
abundant = [i for i, x in enumerate(abundant) if x > i and i != 0]

print(sum(
    set(range(LIMIT)) -
    set(a + b for a, b in itertools.product(abundant, repeat=2))))

