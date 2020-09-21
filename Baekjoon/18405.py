import sys
from collections import deque

n, k = map(int, sys.stdin.readline().rstrip().split())
board = []

for i in range(n):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))

s, x, y = map(int, sys.stdin.readline().rstrip().split())
v = []

for i in range(n):
    for j in range(n):
        if board[i][j] != 0:
            v.append((board[i][j], i, j))

v.sort()
q = deque(v)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

time = 0
while q:
    size = len(q)

    if time == s:
        break

    while size > 0:
        size -= 1
        virus, cur_x, cur_y = q.popleft()

        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx > n - 1 or ny < 0 or ny > n - 1 or board[nx][ny] != 0:
                continue

            board[nx][ny] = board[cur_x][cur_y]
            q.append((virus, nx, ny))
    time += 1

print(board[x - 1][y - 1])
