import itertools
import math

START = 1e12
# START = 19

for m in itertools.count(START):
    inner_sqrt = 2*m*m - 2*m + 1
    sqrt = math.sqrt(inner_sqrt)
    n = sqrt / 2 + 0.5

    # if n % 1 == 0:
    #     print(m, n)

    if int(sqrt) % 2 == 1 and int(sqrt)**2 == inner_sqrt:
        print(m, n)

    # print(m, sqrt, inner_sqrt)
    # assert sqrt**2 <= inner_sqrt < (sqrt + 1)**2

    # if sqrt**2 == inner_sqrt:
    #     n = int(sqrt / 2 + 0.5)
    #     print(m, n)
    #     break
    

