#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<pair<pair<int, int>, pair<int, int>>> nation;

bool comp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.first > b.first.first)
		return true;
	else if (a.first.first == b.first.first) {
		if (a.first.second > b.first.second)
			return true;
		else if (a.first.second == b.first.second) {
			if (a.second.first > b.second.first)
				return true;
			else if (a.second.first == b.second.first)
				return a.second.second == k;
		}
	}
	return false;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int idx, g, s, c;
		cin >> idx >> g >> s >> c;
		nation.push_back(make_pair(make_pair(g, s), make_pair(c, idx)));
	}

	sort(nation.begin(), nation.end(), comp);

	for (int i = 0; i < n; i++) {
		if (nation[i].second.second == k) {
			cout << i + 1 << '\n';
			break;
		}
	}
	return 0;
}