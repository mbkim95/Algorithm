import sys

n = int(sys.stdin.readline().rstrip())
home = list(map(int, sys.stdin.readline().rstrip().split()))
home.sort()

print(home[(n - 1) // 2])
