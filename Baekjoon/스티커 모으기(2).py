def solution(sticker):
    n = len(sticker)
    if n == 1:
        return sticker[0]
    
    dp = [[0] * n for _ in range(2)]
    dp[0][0] = 0
    dp[1][0] = sticker[0]

    for i in range(2):
        for j in range(1, n):
            dp[i][j] = max(dp[i][j - 1], dp[i][j - 2] + sticker[j])
    answer = max(dp[0][-1], dp[1][-2])
    return answer