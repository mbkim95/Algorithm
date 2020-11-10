import sys

n = int(sys.stdin.readline().rstrip())
for i in range(n):
    str = list(sys.stdin.readline().rstrip().split())
    print('Case #%d: ' % (i + 1), end='')
    for j in range(len(str) - 1, -1, -1):
        print(str[j], end=' ')
