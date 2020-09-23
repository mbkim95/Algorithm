import sys

n = int(sys.stdin.readline().rstrip())
s = []
for _ in range(n):
    s.append(int(sys.stdin.readline().rstrip()))
s.sort()
answer = 0
for i in range(n):
    answer += abs(s[i] - (i + 1))
print(answer)
