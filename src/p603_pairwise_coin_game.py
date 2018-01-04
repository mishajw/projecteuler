import itertools

def contains_tt(xs):
    return len([1 for a, b in zip(xs[:-1], xs[1:]) if a and b]) > 0

for games in range(1, 9):
    results = list(itertools.product([True, False], repeat=games))
    num_failures = len([1 for r in results if contains_tt(r)])
    print(num_failures)
    print(games, f"{num_failures} / {len(results)}", num_failures / len(results))

