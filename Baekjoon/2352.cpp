#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num, v;

int solve() {
	v.push_back(-987654321);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v.back() < num[i]) {
			v.push_back(num[i]);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), num[i]);
			*it = num[i];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	num = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << solve() << '\n';
	return 0;
}