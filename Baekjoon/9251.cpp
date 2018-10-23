#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1001][1001];

int LCS() {
	int n = str1.length(), m = str2.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int main() {
	cin >> str1;
	cin >> str2;
	cout << LCS() << '\n';
	return 0;
}