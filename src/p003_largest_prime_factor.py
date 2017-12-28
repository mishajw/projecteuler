x: int = 600851475143
i: int = 2
last_prime = 0
while x != 1:
    if x % i == 0:
        last_prime = i
        x = x // i
    else:
        i += 1

print(last_prime)
    

