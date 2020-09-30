import sys

input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
adj = [[False] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().rstrip().split())
    adj[a][b] = True


def floyd_warshall():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if adj[i][k] and adj[k][j]:
                    adj[i][j] = True


floyd_warshall()

answer = 0
for i in range(1, n + 1):
    count = 0
    for j in range(1, n + 1):
        if adj[i][j] or adj[j][i]:
            count += 1
    if count == n - 1:
        answer += 1
print(answer)
