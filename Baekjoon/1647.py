import sys


def find(x):
    if root[x] != x:
        root[x] = find(root[x])
    return root[x]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        root[b] = a
    else:
        root[a] = b


def kruskal():
    sum = 0
    last = 0
    for i in edges:
        c, a, b = i
        if find(a) == find(b):
            continue
        union(a, b)
        sum += c
        last = c
    return sum - last


n, m = map(int, sys.stdin.readline().rstrip().split())
root = [0 for _ in range(n + 1)]
edges = []

for i in range(1, n + 1):
    root[i] = i

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    edges.append((c, a, b))
edges.sort()

print(kruskal())
