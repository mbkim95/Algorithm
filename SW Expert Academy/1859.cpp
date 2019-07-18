#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int c = 1; c <= t; c++) {
		int n, maxv = 0, ans = 0;
		cin >> n;
		v = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			if (maxv > v[i]) {
				ans += maxv - v[i];
			}
			else
				maxv = v[i];
		}
		cout << "#" << c << ' ' << ans << '\n';
	}
	return 0;
}