import sys
from collections import deque

n, m, k, x = map(int, sys.stdin.readline().rstrip().split())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    adj[a].append(b)

distance = [-1] * (n + 1)


def bfs():
    q = deque([x])
    distance[x] = 0

    while q:
        now = q.popleft()
        if distance[now] > k:
            continue

        for next in adj[now]:
            if distance[next] == -1:
                distance[next] = distance[now] + 1
                q.append(next)


bfs()

find = False
for i in range(1, n + 1):
    if distance[i] == k:
        print(i)
        find = True

if not find:
    print(-1)
