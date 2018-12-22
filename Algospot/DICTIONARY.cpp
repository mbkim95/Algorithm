#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> chk, order;

void dfs(int idx) {
	chk[idx] = 1;

	for (int i = 0; i < 26; i++) {
		if (adj[idx][i] && !chk[i])
			dfs(i);
	}
	order.push_back(idx);
}

bool isDAG() {
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (adj[order[j]][order[i]])
				return false;
		}
	}
	return true;
}

void topologicalSort() {
	chk = vector<int>(26, 0);
	order.clear();
	for (int i = 0; i < 26; i++) {
		if (!chk[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());

	if (isDAG()) {
		for (int i = 0; i < order.size(); i++)
			cout << (char)(order[i] + 'a');
	}
	else {
		cout << "INVALID HYPOTHESIS";
	}
	cout << '\n';
}

void makeGraph(const vector<string>& w) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));

	for (int j = 1; j < w.size(); j++) {
		int i = j - 1, len = min(w[i].size(), w[j].size());

		for (int k = 0; k < len; k++) {
			if (w[i][k] != w[j][k]) {
				int a = w[i][k] - 'a';
				int b = w[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> w(n);
		for (int i = 0; i < n; i++)
			cin >> w[i];
		makeGraph(w);
		topologicalSort();
	}
	return 0;
}