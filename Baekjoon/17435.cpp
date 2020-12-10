#include <iostream>
using namespace std;

const int MAX = 500001;
const int BIT = 19;

int m, q;
int dp[MAX][BIT];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> dp[i][0];

	for (int j = 1; j < BIT; j++)
		for (int i = 1; i <= m; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, x;
		cin >> n >> x;
		for (int j = BIT - 1; j >= 0; j--) {
			if (n >= 1 << j) {
				n -= 1 << j;
				x = dp[x][j];
			}
		}
		cout << x << '\n';
	}
	return 0;
}