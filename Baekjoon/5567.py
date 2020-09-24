import sys
from collections import deque

n = int(sys.stdin.readline().rstrip())
m = int(sys.stdin.readline().rstrip())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    adj[a].append(b)
    adj[b].append(a)


def bfs():
    q = deque([1])
    visit = [False] * (n + 1)
    visit[1] = True

    answer = 0
    count = 0
    while q:
        size = len(q)
        if count == 2:
            break

        while size:
            current = q.popleft()

            for i in adj[current]:
                if not visit[i]:
                    visit[i] = True
                    q.append(i)
                    answer += 1
            size -= 1
        count += 1
    return answer


print(bfs())