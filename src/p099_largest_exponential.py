import math

with open("inputs/p099_base_exp.txt") as f: 
    exps = [(int(b), int(e)) for b, e in [l.split(",") for l in f]]
vals = [math.log(b, 2) * e for b, e in exps]
print(vals.index(max(vals)) + 1)

