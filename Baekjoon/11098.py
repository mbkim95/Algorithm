import sys

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    p = int(sys.stdin.readline().rstrip())
    player = []
    for i in range(p):
        price, name = sys.stdin.readline().rstrip().split()
        player.append((int(price), name))
    player.sort(reverse=True)
    print(player[0][1])
