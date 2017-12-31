with open("inputs/p022_names.txt") as f:
    names = sorted(next(f)[1:-1].split("\",\""))

print(sum(sum(ord(c) - ord('A') + 1 for c in n) * (i + 1) for i, n in enumerate(names)))

