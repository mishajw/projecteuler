import itertools

RING_SIZE = 10

def is_consecutive(xs):
    return all(a + 1 == b for a, b in zip(xs[:-1], xs[1:]))

def rotate(sequences):
    min_ind = sequences.index(min(sequences, key=lambda xs: xs[0]))    
    return sequences[min_ind:] + sequences[:min_ind]

def get_iter():
    for inner_ring in itertools.permutations(range(1, RING_SIZE // 2 + 1)):
        pairs = list(zip(inner_ring, inner_ring[1:] + inner_ring[:1]))
        sums = list(sorted(map(sum, pairs)))
        
        if not is_consecutive(sums):
            continue

        total = sums[0] + RING_SIZE
        sequences = [[total - a - b, a, b] for a, b in pairs]
        yield "".join(str(x) for xs in rotate(sequences) for x in xs)

print(max(get_iter()))

