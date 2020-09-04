import java.util.Arrays;

class Solution {
    static int DIV = 1000000007;
    int dp[][];

    public int solution(int n, int[] money) {
        dp = new int[money.length + 1][n + 1];
        Arrays.sort(money);
        for (int j = 0; j <= n; j++) {
            int coin = money[0];
            if (j % coin == 0)
                dp[1][j] = 1;
        }
        for (int i = 1; i < money.length; i++) {
            int coin = money[i];
            for (int j = 0; j <= n; j++) {
                if (j < coin) dp[i + 1][j] = dp[i][j];
                else dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - coin]) % DIV;
            }
        }
        return dp[money.length][n];
    }
}