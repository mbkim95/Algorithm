#include <iostream>
using namespace std;

int n, s, m;
int v[100];
bool dp[100][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) 
		cin >> v[i];

	if (s + v[0] <= m) dp[0][s + v[0]] = true;
	if (s - v[0] >= 0) dp[0][s - v[0]] = true;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!dp[i - 1][j]) continue;

			if (j + v[i] <= m)
				dp[i][j + v[i]] = true;				
			
			if(j - v[i] >= 0)
				dp[i][j - v[i]] = true;
		}
	}

	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (!dp[n - 1][i]) continue;
		ans = i;
	}
	cout << ans << '\n';
	return 0;
}