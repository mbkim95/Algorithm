#include <iostream>
#include <cstring>
using namespace std;

int n, d, p, r[51][51], N[51];
double dp[101][51];

double solve(int day, int idx) {
	if (day == 0)
		return (idx == p ? 1.0 : 0.0);

	double& ret = dp[day][idx];

	if (ret != -1.0)
		return ret;

	ret = 0;

	for (int i = 0; i < n; i++) {
		if (r[idx][i] == 1)
			ret += (solve(day - 1, i) / N[i]);
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> d >> p;
		memset(N, 0, sizeof(N));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> r[i][j];
				if(r[i][j] == 1)
					N[i]++;
			}
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 51; j++) {
				dp[i][j] = -1.0;
			}
		}
		
		cout.precision(8);
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int tmp;
			cin >> tmp;
			cout << solve(d, tmp) << ' ';
		}
		cout << '\n';			
	}
	return 0;
}