#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> ans(n);
	bool first = true;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		if (i == 0) continue;
		else if (ans[i] < ans[i - 1]) first = false;
	}
	if (first) cout << "-1\n";
	else {
		for (int i = 0; i < 1; i++)
			prev_permutation(ans.begin(), ans.end());
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}