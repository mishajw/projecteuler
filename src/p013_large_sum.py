with open("inputs/p013_large_sum.txt") as f:
    print(str(sum(int(l.strip()) for l in f))[:10])

