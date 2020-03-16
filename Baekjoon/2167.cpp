#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int mat[301][301];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> mat[i][j];
	int k;
	cin >> k;
	for (int t = 0; t < k; t++) {
		int ans = 0;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++) {
			for (int j = b; j <= d; j++) {
				ans += mat[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}