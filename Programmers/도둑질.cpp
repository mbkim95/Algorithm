#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
	int n = money.size();

	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = 0;
	dp[1][0] = money[0];

	for (int i = 1; i < n; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + money[i]);
		dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + money[i]);
	}
	return max(dp[0][n - 1], dp[1][n - 2]);
}