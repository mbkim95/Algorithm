#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int dp(int idx, vector<pair<int, int>>& v, vector<int>& cache) {
	int& ret = cache[idx];

	if (ret != -1)
		return ret;
	
	ret = 1;

	for (int i = idx + 1; i < n; i++) {
		if (v[idx].second < v[i].second)
			ret = max(ret, dp(i, v, cache) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> cache(n, -1);
	for (int i = 0; i < n; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp(i, v, cache));
	}
	cout << n - ans << '\n';
	return 0;
}