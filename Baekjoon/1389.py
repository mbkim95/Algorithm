import sys

input = sys.stdin.readline

INF = 1e9
n, m = map(int, input().rstrip().split())
adj = [[INF] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().rstrip().split())
    adj[a][b] = 1
    adj[b][a] = 1

for i in range(1, n + 1):
    adj[i][i] = 0


def floyd_warshall():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if adj[i][j] > adj[i][k] + adj[k][j]:
                    adj[i][j] = adj[i][k] + adj[k][j]


floyd_warshall()

count = INF
idx = 0
for i in range(1, n + 1):
    cnt = 0
    for j in range(1, n + 1):
        cnt += adj[i][j]
    if count > cnt:
        count = cnt
        idx = i
print(idx)
