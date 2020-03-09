#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool answer;
vector<bool> visited;
vector<vector<int>> relation;

void dfs(int idx, int cnt) {
	if (cnt == 4) {
		answer = true;
		return;
	}

	visited[idx] = true;

	for (int i = 0; i < relation[idx].size(); i++) {
		int next = relation[idx][i];
		if (!visited[next]) {
			dfs(next, cnt + 1);
		}
		if (answer)
			return;
	}
	visited[idx] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	visited = vector<bool>(n, false);
	relation = vector<vector<int>>(n);

	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		relation[tmp1].push_back(tmp2);
		relation[tmp2].push_back(tmp1);
	}

	for (int i = 0; i < n; i++) {
		if (answer) break;
		dfs(i, 0);
	}
	cout << answer ? 1 : 0 << '\n';
	return 0;
}