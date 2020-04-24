#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool finish = false;
int n, r1, r2;
vector<pair<int, int>> adj[100001];
bool visited[100001];

void dfs(int idx, int sum, int max_value){
	if (finish) return;
	if (idx == r2) {
		finish = true;
		cout << sum - max_value << '\n';
		return;
	}

	visited[idx] = true;

	for (auto i : adj[idx]) {
		int next = i.first;
		int value = i.second;
		if (!visited[next]) 
			dfs(next, sum + value, max(max_value, value));
	}
}

int main() {
	cin >> n >> r1 >> r2;
	for (int i = 0; i < n - 1; i++) {
		int tmp1, tmp2, v;
		cin >> tmp1 >> tmp2 >> v;
		adj[tmp1].push_back({ tmp2, v });
		adj[tmp2].push_back({ tmp1, v });
	}

	dfs(r1, 0, 0);
	return 0;
}