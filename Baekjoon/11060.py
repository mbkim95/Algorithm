import sys
from collections import deque

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().rstrip().split()))
visited = [987654321] * n


def bfs():
    q = deque()
    q.append(0)
    visited[0] = 0

    while q:
        cur = q.popleft()

        for i in range(1, a[cur] + 1):
            if cur + i >= n: # 범위를 벗어나면 멈춘다
                break
            if visited[cur + i] > visited[cur] + 1:
                visited[cur + i] = visited[cur] + 1
                q.append(cur + i)
    if visited[n - 1] == 987654321:
        return -1
    else:
        return visited[n - 1]


print(bfs())
