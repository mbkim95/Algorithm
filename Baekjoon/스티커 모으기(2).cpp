#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker){    
    int n = sticker.size();
    
    if(n == 1) return sticker[0];
    
    vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = 0;
	dp[1][0] = sticker[0];

	for (int i = 1; i < n; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + sticker[i]);
		dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + sticker[i]);
	}
	return max(dp[0][n - 1], dp[1][n - 2]);
}