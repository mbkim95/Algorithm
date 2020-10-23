import sys
import math

MAX = 4000000
input = sys.stdin


def pre_calc():
    for i in range(2, int(math.sqrt(MAX)) + 1):
        if p[i]:
            j = 2
            while i * j <= MAX:
                p[i * j] = False
                j += 1
    for i in range(2, MAX + 1):
        if p[i]:
            prime.append(i)


def two_pointer():
    ret = 0
    s = 0
    e = 0
    sum = prime[0]

    while e < len(prime):
        if sum <= n:
            if sum == n:
                ret += 1
            e += 1
            if e == len(prime):
                break
            sum += prime[e]
        else:
            sum -= prime[s]
            s += 1
    return ret


n = int(input.readline())
p = [True for _ in range(MAX + 1)]
prime = []

pre_calc()
print(two_pointer())