#include <iostream>
using namespace std;

int students[2][7];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;
		students[s][y]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			int s = students[i][j];
			if (s % k == 0) ans += s / k;
			else ans += (s / k + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}