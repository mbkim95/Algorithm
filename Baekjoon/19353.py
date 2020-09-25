import sys
from bisect import bisect_left

n = int(sys.stdin.readline().rstrip())
soldiers = list(map(int, sys.stdin.readline().rstrip().split()))

soldiers.reverse()


def get_lis():
    if n == 1:
        return 0

    lis = [soldiers[0]]

    for i in range(1, n):
        if lis[-1] < soldiers[i]:
            lis.append(soldiers[i])
        else:
            idx = bisect_left(lis, soldiers[i])
            lis[idx] = soldiers[i]
    return n - len(lis)


print(get_lis())
