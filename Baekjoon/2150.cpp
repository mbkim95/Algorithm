#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_V = 10001;

int v, e, id;
bool finished[MAX_V];
int visited[MAX_V];
vector<int> adj[MAX_V];
vector<vector<int>> scc;
stack<int> st;

bool cmp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int dfs(int idx) {
	visited[idx] = ++id;
	st.push(idx);

	int parent = visited[idx];
	for (int next : adj[idx]) {
		if (visited[next] == 0)
			parent = min(parent, dfs(next));
		else if (!finished[next])
			parent = min(parent, visited[next]);
	}

	if (parent == visited[idx]) {
		vector<int> tmp;
		while (true) {
			int t = st.top();
			st.pop();
			tmp.push_back(t);
			finished[t] = true;
			if (t == idx) break;
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0)
			dfs(i);
	}

	sort(scc.begin(), scc.end(), cmp);
	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); i++) {
		for (int node : scc[i])
			cout << node << ' ';
		cout << "-1\n";
	}
	return 0;
}