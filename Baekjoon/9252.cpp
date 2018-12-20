#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string s1, s2, ans;
int dp[1001][1001];
bool f1 = false, f2 = false;

int solve(int idx1, int idx2) {
	int& ret = dp[idx1][idx2];

	if (ret != -1)
		return ret;

	if (idx1 == s1.length() || idx2 == s2.length()) {
		return 0;
	}
	
	if (s1[idx1] == s2[idx2])
		return ret = 1 + solve(idx1 + 1, idx2 + 1);

	return ret = max(solve(idx1 + 1, idx2), solve(idx1, idx2 + 1));
}

void findLCS(int idx1, int idx2) {
	if (idx1 == s1.length() || idx2 == s2.length())
		return;

	if (s1[idx1] == s2[idx2]) {
		ans += s1[idx1];
		findLCS(idx1 + 1, idx2 + 1);
	}else if (dp[idx1 + 1][idx2] >= dp[idx1][idx2 + 1])
		findLCS(idx1 + 1, idx2);
	else
		findLCS(idx1, idx2 + 1);
}

int main() {
	cin >> s1;
	cin >> s2;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	findLCS(0, 0);
	cout << ans << '\n';
	return 0;
}