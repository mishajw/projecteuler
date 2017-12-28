import itertools

fibs = [1, 2]
for i in itertools.count():
    fibs.append(fibs[-1] + fibs[-2])
    if fibs[-1] > 4000000:
        break

print(sum(i for i in fibs if i % 2 == 0))

