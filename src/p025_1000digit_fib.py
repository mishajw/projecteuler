import itertools

LIMIT = 10**999

fibs = [1, 1]
for i in itertools.count():
    next_fib = fibs[-1] + fibs[-2]
    fibs.append(next_fib)

    if next_fib >= LIMIT:
        print(i + 3)
        break

