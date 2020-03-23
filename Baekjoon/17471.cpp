#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define INF 987654321
using namespace std;


int n, limit, ans = INF;
int p[11];
vector<int> adj[11];
bool visited[11];
set<int> a, b;

int bfs(set<int>& group) {
	queue<int> q;
	vector<bool> group_check(n + 1, false);
	q.push(*group.begin());
	group_check[*group.begin()] = true;
	int cnt = 1;
	int sum = p[*group.begin()];

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			if (group.find(next) != group.end() && !group_check[next]) {
				q.push(next);
				group_check[next] = true;
				sum += p[next];
				cnt++;
			}
		}
	}

	if (group.size() != cnt) return INF;
	return sum;
}

int calculate() {
	int ret = INF;
	a.clear();
	b.clear();
	for (int i = 1; i <= n; i++)
		if (visited[i])
			a.insert(i);
		else
			b.insert(i);

	if (a.size() == 0 || b.size() == 0) return INF;

	int result1 = bfs(a);
	int result2 = bfs(b);

	if (result1 != INF && result2 != INF)
		ret = abs(result1 - result2);
	return ret;
}

void dfs(int idx, int cnt) {
	if (idx > n) return;

	int result = calculate();
	if (result != INF) {
		if (result < ans) {
			ans = result;
		}
	}

	visited[idx] = true;
	dfs(idx + 1, cnt + 1);
	visited[idx] = false;
	dfs(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	limit = n % 2 == 0 ? n / 2 : (n - 1) / 2;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp;
			cin >> tmp;
			adj[i].push_back(tmp);
		}
	}
	dfs(0, 0);

	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}