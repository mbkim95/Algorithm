#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> w;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	w = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w.begin(), w.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (w[i] > ans + 1)
			break;
		ans += w[i];
	}
	cout << ans + 1 << '\n';
	return 0;
}
