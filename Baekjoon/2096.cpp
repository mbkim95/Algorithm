#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[3][2];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int t1 = dp[0][0];
		int t2 = dp[1][0];
		int t3 = dp[2][0]; 
		int t4 = dp[0][1];
		int t5 = dp[1][1];
		int t6 = dp[2][1];
		dp[0][0] = max(t1, t2) + a;
		dp[1][0] = max(max(t1, t2), t3) + b;
		dp[2][0] = max(t2, t3) + c;
		dp[0][1] = min(t4, t5) + a;
		dp[1][1] = min(min(t4, t5), t6) + b;
		dp[2][1] = min(t5, t6) + c;
	}
	int max_value = max(max(dp[0][0], dp[1][0]), dp[2][0]);
	int min_value = min(min(dp[0][1], dp[1][1]), dp[2][1]);
	cout << max_value << ' ' << min_value << '\n';
	return 0;
}