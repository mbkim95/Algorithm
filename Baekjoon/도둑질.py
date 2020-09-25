def solution(money):
    n = len(money)

    dp = [[0] * n for _ in range(2)]
    dp[0][0] = 0
    dp[1][0] = money[0]

    for i in range(2):
        for j in range(1, n):
            dp[i][j] = max(dp[i][j - 1], dp[i][j - 2] + money[j])
    answer = max(dp[0][-1], dp[1][-2])
    return answer