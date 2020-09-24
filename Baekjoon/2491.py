import sys
from bisect import bisect_left

n = int(sys.stdin.readline().rstrip())
num = list(map(int, sys.stdin.readline().rstrip().split()))


def two_pointer():
    left = 0
    right = 0
    last_value = 0
    ret = 0
    while True:
        if left == right:
            last_value = num[right]
            right += 1
            ret = max(ret, right - left)
        elif right == n:
            break
        elif num[right] >= last_value:
            last_value = num[right]
            right += 1
            ret = max(ret, right - left)
        else:
            left += 1
    return ret


answer = two_pointer()
num.reverse()
answer = max(answer, two_pointer())
print(answer)
