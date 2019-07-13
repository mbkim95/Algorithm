#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n, ans;
vector<int> v;
int alpha[26];

void solve() {
	for (int i = 0; i < 26; i++) {
		if (alpha[i])
			v.push_back(alpha[i]);
	}

	sort(v.begin(), v.end(), greater<int>());

	int num = 9;
	for (int i = 0; i < v.size(); i++) {
		ans += (v[i] * (num--));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			alpha[tmp[j] - 65] += (int)pow(10, tmp.length() - 1 - j);
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}