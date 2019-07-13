#include <iostream>
using namespace std;

int n, m, a, b;
int num[100001], dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << dp[b] - dp[a-1] << '\n';
	}
	return 0;
}