n, m = map(int, input().split())
if m in [1, 2]:
    print("NEWBIE!")
elif m <= n:
    print("OLDBIE!")
else:
    print("TLE!")
