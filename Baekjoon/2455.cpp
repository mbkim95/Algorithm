#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v;
int ans;

int main() {
	for (int i = 0; i < 4; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}

	ans = max(ans, v[0].second);
	ans = max(ans, ans - v[1].first + v[1].second);
	ans = max(ans, ans - v[2].first + v[2].second);
	cout << ans << '\n';
	return 0;
}