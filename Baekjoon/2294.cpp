#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int c[101], dp[10001];

int main() {
	int n, k;
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 1; i <= k; i++)
		dp[i] = 987654321;

	for (int i = 0; i < n; i++)
		for (int j = c[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - c[i]] + 1);

	int ans = dp[k];
	ans == 987654321 ? ans = -1 : ans;
	cout << ans << endl;
}