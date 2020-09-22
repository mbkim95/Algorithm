import sys

n = int(sys.stdin.readline().rstrip())
board = []
for i in range(n):
    board.append(list(sys.stdin.readline().rstrip().split()))

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
answer = 0

cand = []
teachers = []

for i in range(n):
    for j in range(n):
        if board[i][j] == 'X':
            cand.append((j, i))
        elif board[i][j] == 'T':
            teachers.append((j, i))


def dfs(idx, count):
    if count == 3:
        global answer
        answer += check()
        return

    for i in range(idx + 1, len(cand)):
        x = cand[i][0]
        y = cand[i][1]
        board[y][x] = 'O'
        dfs(i, count + 1)
        board[y][x] = 'X'


def check():
    for t in teachers:
        for i in range(4):
            nx = t[0]
            ny = t[1]
            while True:
                nx += dx[i]
                ny += dy[i]
                if (nx < 0 or nx > n - 1 or ny < 0 or ny > n - 1 or board[ny][nx] == 'O'):
                    break
                if board[ny][nx] == 'S':
                    return 0
    return 1


dfs(-1, 0)

if answer == 0:
    print('NO')
else:
    print('YES')