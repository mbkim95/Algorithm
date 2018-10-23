#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
double dp[1001][2001];

double solve(int days, int total) {
	if (days == m)
		return total >= n ? 1 : 0;

	double& ret = dp[days][total];

	if (ret != -1.0)
		return ret;

	ret = (0.25 * solve(days + 1, total + 1)) + (0.75 * solve(days + 1, total + 2));
	return ret;
}


int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= 2*m; j++)
				dp[i][j] = -1.0;
		cout.precision(11);
		cout  << solve(0, 0) << '\n';		
	}
	return 0;
}