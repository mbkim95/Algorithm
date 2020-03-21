#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int w[11][11];
bool visited[11];
int ans = 987654321;
vector<int> path;

bool checkAllVisited() {
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			return false;
	return true;
}

void dfs(int idx, int sum, int start) {
	if (checkAllVisited() && start == idx) {
		if (ans > sum) ans = sum;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (w[idx][i] > 0 && !visited[i]) {
			if (ans > sum + w[idx][i]) {
				visited[i] = true;
				path.push_back(i);
				dfs(i, sum + w[idx][i], start);
				path.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];

	for (int i = 1; i <= n; i++) {
		path.push_back(i);
		dfs(i, 0, i);
		path.pop_back();
	}
	cout << ans << '\n';
	return 0;
}