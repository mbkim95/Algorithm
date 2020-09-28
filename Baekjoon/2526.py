import sys

n, p = map(int, sys.stdin.readline().rstrip().split())

s = set()
overlap = set()
num = n
while True:
    num *= n
    num %= p
    if num in s:
        if num in overlap:
            break
        else:
            overlap.add(num)
    else:
        s.add(num)

print(len(overlap))
