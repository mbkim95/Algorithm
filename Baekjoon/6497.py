import sys

input = sys.stdin


def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


def kruskal():
    edges.sort()
    sum = 0
    for i in edges:
        x = i[1][0]
        y = i[1][1]
        dist = i[0]
        if find(x) == find(y):
            continue
        sum += dist
        union(x, y)
    return sum


while True:
    m, n = map(int, input.readline().rstrip().split())

    if m == 0 and n == 0:
        break

    parent = [0] * (m + 1)
    edges = []

    for i in range(1, m + 1):
        parent[i] = i

    total_dist = 0
    for _ in range(n):
        x, y, z = map(int, input.readline().rstrip().split())
        edges.append((z, (x, y)))
        total_dist += z
    print(total_dist - kruskal())
