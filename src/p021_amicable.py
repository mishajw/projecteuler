from peutil import get_divisors

total = 0
for i in range(1, 10000):
    j = sum(get_divisors(i)) - i
    # print(i, j)
    # print(get_divisors(i))
    # print(get_divisors(j))
    if i != j and sum(get_divisors(j)) - j == i:
        total += i
        print(i, j)
print(total)

