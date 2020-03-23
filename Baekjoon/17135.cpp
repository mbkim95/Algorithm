#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, d, ans = 0;
vector<vector<int>> field;
vector<pair<int, int>> enemy, bow;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

int simulation() {
	vector<vector<int>> s_field = field;
	vector<pair<int, int>> s_enemy = enemy;
	int maxY = 0;
	int ret = 0;
	while (true) {
		if (s_enemy.size() == 0) {
			break;
		}
		sort(s_enemy.begin(), s_enemy.end());
		vector<bool> chk(s_enemy.size(), false);
		for (int i = 0; i < 3; i++) {
			int bx = bow[i].first;
			int by = bow[i].second;
			bool find = false;
			for (int j = 1; j <= d; j++) {
				for (int k = 0; k < s_enemy.size(); k++) {
					int ex = s_enemy[k].first;
					int ey = s_enemy[k].second;
					if (abs(bx - ex) + abs(by - ey) == j) {
						chk[k] = true;
						find = true;
						break;
					}
				}
				if (find)
					break;
			}
		}
		vector<pair<int, int>> tmp;
		for (int i = 0; i < s_enemy.size(); i++) {
			if (chk[i])
				ret++;
			if (!chk[i] && s_enemy[i].second + 1 < n)
				tmp.push_back({ s_enemy[i].first, s_enemy[i].second + 1 });

		}
		s_enemy = tmp;
	}
	return ret;
}

void dfs(int idx, int cnt) {
	if (ans == enemy.size()) return;

	if (idx == m + 1) return;

	if (cnt == 3) {
		int tmp = simulation();
		if (ans < tmp)
			ans = tmp;
		return;
	}

	bow.push_back({ idx, n });
	dfs(idx + 1, cnt + 1);
	bow.pop_back();
	dfs(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> d;
	field = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 1)
				enemy.push_back({ j, i });
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}