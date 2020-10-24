#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	vector<int> b(w);
	vector<vector<int>> dp(2, vector<int>(w));

	for (int i = 0; i < w; i++)
		cin >> b[i];

	int ans = 0;
	dp[0][0] = b[0];
	for (int i = 1; i < w; i++)
		dp[0][i] = max(dp[0][i - 1], b[i]);

	dp[1][w - 1] = b[w - 1];
	for (int i = w - 2; i >= 0; i--)
		dp[1][i] = max(dp[1][i + 1], b[i]);

	for (int i = 1; i < w; i++)
		ans += (min(dp[0][i], dp[1][i]) - b[i]);
	cout << ans << '\n';
	return 0;
}