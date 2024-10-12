with open('forest.in', 'r') as fin:
    A, K, B, M, X = map(int, fin.readline().split())

def possible(h):
    return (h - h // K) * A + (h - h // M) * B;

def min_possible():
    l = 0
    r = 10 ** 36;

    while (l < r):
        m = (l + r) // 2;

        if (possible(m) < X):
            l = m + 1;
        else:
            r = m;

    return l;

with open('forest.out', 'w') as fout:           
    print(min_possible(), file=fout)