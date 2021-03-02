#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end(), cmp);

	int min_time = 0;

	for (int i = 0; i < n; i++) {
		int s = v[i].first;
		int e = v[i].second;
		if (s >= min_time) {
			min_time = e;
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
