import sys


class Planet:
    def __init__(self, idx, x, y, z):
        self.idx = idx
        self.x = x
        self.y = y
        self.z = z


def find(a):
    if a != parent[a]:
        parent[a] = find(parent[a])
    return parent[a]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


def kruskal():
    sum = 0
    for i in edges:
        a = i[1]
        b = i[2]
        c = i[0]
        if find(a) == find(b):
            continue
        union(a, b)
        sum += c
    return sum


n = int(sys.stdin.readline().rstrip())
parent = [0 for _ in range(n)]
p = []
edges = []

for i in range(n):
    parent[i] = i

for i in range(n):
    x, y, z = map(int, sys.stdin.readline().rstrip().split())
    p.append(Planet(i, x, y, z))

p.sort(key=lambda planet: planet.x)
for i in range(n - 1):
    edges.append((p[i + 1].x - p[i].x, p[i].idx, p[i + 1].idx))

p.sort(key=lambda planet: planet.y)
for i in range(n - 1):
    edges.append((p[i + 1].y - p[i].y, p[i].idx, p[i + 1].idx))

p.sort(key=lambda planet: planet.z)
for i in range(n - 1):
    edges.append((p[i + 1].z - p[i].z, p[i].idx, p[i + 1].idx))
edges.sort()
print(kruskal())
