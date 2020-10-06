import sys
from collections import deque


def topological_sort():
    result = []
    q = deque()

    for i in range(1, n + 1):
        if in_degree[i] == 0:
            q.append(i)

    is_cycle = False
    is_certain = True

    for i in range(n):
        if len(q) == 0:
            is_cycle = True
            break
        elif len(q) >= 2:
            is_certain = False
            break
        cur = q.popleft()
        result.append(cur)

        for j in range(1, n + 1):
            if adj[cur][j]:
                in_degree[j] -= 1
                if in_degree[j] == 0:
                    q.append(j)
    if is_cycle:
        print("IMPOSSIBLE")
    elif not is_certain:
        print("?")
    else:
        for i in result:
            print(i, end=' ')
        print()


t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    in_degree = [0 for _ in range(n + 1)]
    adj = [[False] * (n + 1) for _ in range(n + 1)]
    ranking = list(map(int, sys.stdin.readline().rstrip().split()))

    for i in range(n - 1):
        for j in range(i + 1, n):
            adj[ranking[i]][ranking[j]] = True
            in_degree[ranking[j]] += 1
    m = int(sys.stdin.readline().rstrip())
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().rstrip().split())
        if adj[a][b]:
            adj[a][b] = False
            adj[b][a] = True
            in_degree[a] += 1
            in_degree[b] -= 1
        else:
            adj[a][b] = True
            adj[b][a] = False
            in_degree[a] -= 1
            in_degree[b] += 1
    topological_sort()
