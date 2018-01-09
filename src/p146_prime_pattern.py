LIMIT = 150000000
INCRS = [1, 3, 7, 9, 13, 27]
NON_PRIME_INCRS = [5, 11, 15, 17, 19, 21, 23, 25]

def are_primes(xs, limit):
    for x in xs:
        if x % 2 == 0 or x % 3 == 0:
            return False

    i = 5
    w = 2
    while i <= limit:
        for x in xs:
            if i * i <= x and x % i == 0:
                return False
        i += w
        w = 6 - w
    return True

def check(x):
    if x % 1000000 == 0:
        print(x)

    if x % 3 == 0 or x % 7 == 0 or x % 13 == 0:
        return False

    squared = x * x
    limit = (x + 27) ** 0.5
    
    if are_primes([squared + i for i in INCRS], limit):
        return all(not are_primes([squared + i], limit) for i in NON_PRIME_INCRS)
    return False

print("eh")

print(sum(i for i in range(10, LIMIT + 1, 2) if check(i)))

