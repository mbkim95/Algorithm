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
        power[a] += power[b]
    else:
        root[a] = b
        power[b] += power[a]


def fight(a, b):
    a = find(a)
    b = find(b)
    if power[a] > power[b]:
        power[a] -= power[b]
        root[b] = a
    elif power[a] < power[b]:
        power[b] -= power[a]
        root[a] = b

    else:
        root[a] = 0
        root[b] = 0


n, m = map(int, sys.stdin.readline().rstrip().split())
root = [0 for _ in range(n + 1)]
power = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    root[i] = i

for i in range(1, n + 1):
    power[i] = int(sys.stdin.readline())
for _ in range(m):
    o, p, q = map(int, sys.stdin.readline().rstrip().split())
    if o == 1:
        union(p, q)
    else:
        fight(p, q)

s = set()
ans = []
for i in range(1, n + 1):
    p = find(i)
    if p != 0:
        s.add(find(i))

for i in s:
    ans.append(power[i])
ans.sort()
print(len(s))
for i in ans:
    print(i, end=' ')
