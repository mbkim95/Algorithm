import sys

n = int(sys.stdin.readline().rstrip())
dp = [0] * 10001
dp[1] = 1

for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]
print(dp[n])
