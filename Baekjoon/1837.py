(pq, k) = map(int, input().split())
is_good = True
for i in range(2, k):
    if pq % i == 0:
        is_good = False
        print(f'BAD {i}')
        break
if is_good:
    print("GOOD")
