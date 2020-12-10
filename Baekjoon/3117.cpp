#include <iostream>
using namespace std;

const int BIT = 30;
const int MAX = 100001;

int n, m, k;
int s[MAX];
int dp[MAX][BIT + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= k; i++)
		cin >> dp[i][0];

	for (int j = 1; j <= BIT; j++)
		for (int i = 1; i <= k; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];

	for (int i = 1; i <= n; i++) {
		int t = m - 1;
		int v = s[i];
		for (int j = BIT; j >= 0; j--) {
			if (t >= 1 << j) {
				t -= 1 << j;
				v = dp[v][j];
			}
		}
		cout << v << ' ';
	}
}