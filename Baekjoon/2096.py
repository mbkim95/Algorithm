import sys

n = int(sys.stdin.readline().rstrip())
dp = [[0] * 2 for _ in range(3)]
while n > 0:
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    n -= 1
    t1 = dp[0][0]
    t2 = dp[1][0]
    t3 = dp[2][0]
    t4 = dp[0][1]
    t5 = dp[1][1]
    t6 = dp[2][1]
    dp[0][0] = max(t1, t2) + a
    dp[1][0] = max(max(t1, t2), t3) + b
    dp[2][0] = max(t2, t3) + c
    dp[0][1] = min(t4, t5) + a
    dp[1][1] = min(min(t4, t5), t6) + b
    dp[2][1] = min(t5, t6) + c
max_value = max(max(dp[0][0], dp[1][0]), dp[2][0])
min_value = min(min(dp[0][1], dp[1][1]), dp[2][1])
print(max_value, min_value)
