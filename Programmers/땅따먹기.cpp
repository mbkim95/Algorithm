#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
	int answer = 0;
	vector<vector<int>> dp(land.size(), vector<int>(land[0].size(), 0));
	for (int i = 0; i < land[0].size(); i++) dp[0][i] = land[0][i];
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < land[0].size(); j++) {
			for (int l = 0; l < land[0].size(); l++) {
				if (j == l) continue;
				dp[i][j] = max(dp[i][j], dp[i-1][l] + land[i][j]);
			}
		}
	}

	for (int i : dp[dp.size() - 1])
		answer = max(answer, i);
	return answer;
}