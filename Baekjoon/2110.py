import sys

n, c = map(int, sys.stdin.readline().rstrip().split())
h = []

for _ in range(n):
    h.append(int(sys.stdin.readline().rstrip()))

h.sort()

left = 1
right = h[-1] - h[0]
answer = 0

while left <= right:
    mid = (left + right) // 2
    start = h[0]
    count = 1

    for i in range(1, n):
        if mid <= h[i] - start:
            count += 1
            start = h[i]

    if count < c:
        right = mid - 1
    else:
        answer = max(answer, mid)
        left = mid + 1

print(answer)
