a, d, k = map(int, input().split())

n = 1
while True:
    num = a + (n - 1) * d
    if num == k:
        print(n)
        break
    elif d > 0 and num > k:
        print("X")
        break
    elif d < 0 and num < k:
        print("X")
        break
    n += 1
