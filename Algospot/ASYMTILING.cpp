#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int n, dp[101];

int tiling(int w) {
	if (w <= 1)
		return 1;
	int& ret = dp[w];

	if (ret != -1)
		return ret;

	return ret = (tiling(w - 1) + tiling(w - 2)) % MOD;
}

int asymmetric(int w) {
	if (w % 2 == 1) 
		return (tiling(w) - tiling(w / 2) + MOD) % MOD;

	int ret = tiling(w);
	ret = (ret - tiling(w / 2) + MOD) % MOD;
	ret = (ret - tiling(w / 2 - 1) + MOD) % MOD;
	return ret;	
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << asymmetric(n) << '\n';
	}
	return 0;
}