import sys
from collections import deque

n, m = map(int, sys.stdin.readline().rstrip().split())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    adj[a].append((b, c))
    adj[b].append((a, c))
start, end = map(int, sys.stdin.readline().rstrip().split())

answer = 0
is_possible = False


def bfs(weight):
    global is_possible
    global answer

    q = deque([start])
    visited = [False] * (n + 1)
    visited[start] = True

    while q:
        current = q.popleft()
        if current == end:
            is_possible = True
            answer = max(answer, weight)
            break

        for i in adj[current]:
            j, w = i[0], i[1]
            if not visited[j] and w >= weight:
                q.append(j)
                visited[j] = True


def binary_search():
    global is_possible
    left = 1
    right = 1e9

    while left <= right:
        mid = int((left + right) / 2)

        is_possible = False
        bfs(mid)

        if is_possible:
            left = mid + 1
        else:
            right = mid - 1


binary_search()
print(answer)