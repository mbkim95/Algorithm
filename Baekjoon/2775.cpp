#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& apt, int floor, int ho) {
	int& ret = apt[floor][ho];

	if (ho == 1)
		return ret = 1;

	if (floor == 0)
		return ret = ho;

	if (ret != -1)
		return ret;

	return ret = solve(apt, floor, ho - 1) + solve(apt, floor - 1, ho);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		vector<vector<int>> apt(k + 1, vector<int>(n + 1, -1));
		cout << solve(apt, k, n) << '\n';
	}
	return 0;
}