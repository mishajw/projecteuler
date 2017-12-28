import itertools

max_palindrome = 0

for i, j in itertools.permutations(reversed(range(100, 1000)), 2):
    x = i * j
    s = str(x)
    s_rev = s[::-1]

    # print(s, s_rev)
    if s == s_rev:
        if x > max_palindrome:
            max_palindrome = x
            print(i, j, x)

