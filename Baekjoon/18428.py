import sys
from itertools import combinations

n = int(sys.stdin.readline().rstrip())
board = []  # 복도 저장 리스트
cand = []  # 빈 공간 저장할 리스트
teachers = []  # 선생님들 위치를 저장할 리스트

for i in range(n):
    board.append(list(sys.stdin.readline().rstrip().split()))
    for j in range(n):
        if board[i][j] == 'X':
            cand.append((j, i))
        elif board[i][j] == 'T':
            teachers.append((j, i))

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
answer = 0


# 빈 공간 3개를 선택해 장애물을 설치
def set_obstacles():
    for obs in combinations(cand, 3):
        for x, y in obs:
            board[y][x] = 'O'

        global answer
        answer += check()
        if answer > 0: break

        for x, y in obs:
            board[y][x] = 'X'


# 감시를 피할 수 있는지 체크하는 함수
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


set_obstacles()

if answer == 0:
    print('NO')
else:
    print('YES')
