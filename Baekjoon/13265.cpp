#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool is_possible;
vector<int> circle;
vector<vector<int>> line;

void dfs(int idx) {
	for (auto i : line[idx]) {
		if (!circle[i]) {
			circle[i] = 3 - circle[idx];
			dfs(i);
		}
		if (circle[idx] == circle[i]) is_possible = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		circle = vector<int>(n + 1);
		line = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			line[tmp1].push_back(tmp2);
			line[tmp2].push_back(tmp1);
		}
		is_possible = true;
		for (int i = 1; i <= n; i++)
			if (!circle[i]) {
				circle[i] = 1;
				dfs(i);
			}
		if (is_possible) cout << "possible\n";
		else cout << "impossible\n";
	}
}