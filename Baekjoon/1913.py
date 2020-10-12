import sys

n = int(sys.stdin.readline().rstrip())
num = int(sys.stdin.readline().rstrip())

arr = [[0] * n for _ in range(n)]


def snail(x, y, len, start):
    if len == 0:
        arr[y][x] = start
        return

    for i in range(len):
        arr[y + i][x] = start
        start -= 1
    for i in range(len):
        arr[y + len][x + i] = start
        start -= 1
    for i in range(len):
        arr[y + len - i][x + len] = start
        start -= 1
    for i in range(len):
        arr[y][x + len - i] = start
        start -= 1
    snail(x + 1, y + 1, len - 2, start)


snail(0, 0, n - 1, n * n)

num_x = 0
num_y = 0
for i in range(n):
    for j in range(n):
        print(arr[i][j], end=' ')
        if arr[i][j] == num:
            num_x = j
            num_y = i
    print()
print(num_y + 1, num_x + 1)
