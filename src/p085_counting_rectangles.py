import itertools

LIMIT = 200
FIND = int(2e6)

min_diff = 1e9
min_prod = 0
for x in range(1, LIMIT):
    for y in range(1, LIMIT):
        num_rects = sum(
            (x + 1 - i) * (y + 1 - j)
            for i, j in itertools.product(range(1, x + 1), range(1, y + 1)))
        diff = abs(FIND - num_rects)

        if num_rects > FIND and diff > min_diff:
            break

        if diff < min_diff:
            min_diff = diff
            min_prod = x * y

print(min_prod)

