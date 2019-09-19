def hanoi(n, f, t, b):
    if n == 1:
        print('%d %d'%(f, t))
        return
    hanoi(n-1, f, b, t)
    hanoi(n-1, b, t, f)
    print('%d %d'%(f, t))

k = int(input())
print('%d'%((1 << k) - 1))
if k <= 20:
    hanoi(k, 1, 3, 2)