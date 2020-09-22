arr = []


def draw(x, y, cnt, num):
    if cnt < 1:
        return

    number = num
    for i in range(cnt):
        arr[y + i][x] = number
        number += 1
    for i in range(1, cnt):
        arr[y + cnt - 1][x + i] = number
        number += 1
    for i in range(1, cnt - 1):
        arr[y + cnt - 1 - i][x + cnt - 1 - i] = number
        number += 1
    draw(x + 1, y + 2, cnt - 3, number)


def solution(n):
    global arr
    arr = [[0] * n for _ in range(n)]
    draw(0, 0, n, 1)

    answer = []
    for i in range(n):
        for j in range(i + 1):
            answer.append(arr[i][j])
    return answer