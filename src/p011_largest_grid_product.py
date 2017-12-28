from functools import reduce

with open("inputs/p011_largest_grid_product.txt") as f:
    grid = [[int(s) for s in line.split(" ")] for line in f]

def get_sequence(x_start, y_start, x_incr, y_incr):
    for i in range(4):
        yield grid[x_start + x_incr * i][y_start + y_incr * i]


def get_all_sequences():
    for x in range(len(grid) - 4):
        for y in range(len(grid[x]) - 4):
            yield get_sequence(x, y, 0, 1)
            yield get_sequence(x, y, 1, 0)
            yield get_sequence(x, y, 0, -1)
            yield get_sequence(x, y, 1, 0)
            yield get_sequence(x, y, 1, 1)
            yield get_sequence(x, y, 1, -1)
            yield get_sequence(x, y, -1, 1)
            yield get_sequence(x, y, -1, -1)

print(max(reduce(lambda x, y: x * y, xs) for xs in get_all_sequences()))

