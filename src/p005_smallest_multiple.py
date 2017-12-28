def get_prime_factors(x):
    i: int = 2
    prime_factors = []
    while x != 1:
        if x % i == 0:
            prime_factors.append(i)
            x = x // i
        else:
            i += 1
    return prime_factors

all_prime_factors = []
all_factors = []
for i in range(1, 21):
    prime_factors = get_prime_factors(i)
    all_prime_factors.append(prime_factors)
    all_factors.extend(prime_factors)

result = 1
for i in range(2, max(all_factors) + 1):
    num_i = max(pfs.count(i) for pfs in all_prime_factors)
    result *= i ** num_i

print(result)

