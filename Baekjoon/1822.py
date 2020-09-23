import sys
from bisect import bisect_left, bisect_right

n1, n2 = map(int, sys.stdin.readline().rstrip().split())
a = list(map(int, sys.stdin.readline().rstrip().split()))
b = set(map(int, sys.stdin.readline().rstrip().split()))

answer = []
for i in a:
    if i not in b:
        answer.append(i)
answer.sort()
print(len(answer))
for i in answer:
    print(i, end=' ')