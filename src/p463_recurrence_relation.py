
f_results = {}
def f_cached(x):
    if x in f_results:
        return f_results[x]
    
    result = f(x)
    f_results[x] = result
    return result

def f(x):
    if x == 1:
        print(f"f({x}) = 1")
        return 1
    elif x == 3:
        print(f"f({x}) = 3")
        return 3

    if x % 2 == 0:
        print(f"f({x}) = f({x // 2})")
        return f(x // 2)

    mod4 = x % 4
    n = (x - mod4) // 4

    if mod4 == 1:
        print(f"f({x}) = 2f(2({n}) + 1) - f({n})")
        return 2 * f(2 * n + 1) - f(n)
    elif mod4 == 3:
        print(f"f({x}) = 3f(2({n}) + 1) - 2f({n})")
        # print("4n+3", x, x // 2, x // 4)
        return 3 * f(2 * n + 1) - 2 * f(n)

# print("sum", sum(f(i) for i in range(1, 3**37 + 1)))

for i in range(1, 100):
    print(i, f_cached(i))

# for i in range(1, 100):
#     print(i, f(i))

# print(f(18))
#
