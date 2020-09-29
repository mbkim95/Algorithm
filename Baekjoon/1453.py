import sys

n = int(sys.stdin.readline().rstrip())
p = list(map(int, sys.stdin.readline().rstrip().split()))
pc = [False] * 101

answer = 0
for i in range(len(p)):
    if pc[p[i]]:
        answer += 1
    else:
        pc[p[i]] = True
print(answer)
