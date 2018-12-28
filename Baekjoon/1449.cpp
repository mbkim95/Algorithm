#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
vector<int> v, chk;

int main() {
	cin >> n >> l;
	v = vector<int>(n, 0);
	chk = vector<int>(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			int tmp = v[i] - 0.5 + l;
			ans++;
			for (int j = i + 1; j < n; j++) {
				if (v[i] - 0.5 <= v[j] && v[j] <= tmp)
					chk[j] = 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}