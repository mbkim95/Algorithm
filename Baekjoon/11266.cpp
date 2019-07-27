#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int here, bool isRoot) {
	discovered[here] = counter++;
	int ret = discovered[here];

	int children = 0;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			children++;
			int subtree = findCutVertex(there, false);

			if (!isRoot && subtree >= discovered[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}

	if (isRoot)
		isCutVertex[here] = (children >= 2);
	return ret;
}

void solve() {
	for (int i = 1; i <= v; i++) {
		if (discovered[i] == -1)
			findCutVertex(i, true);
	}

	vector<int> ans;
	for (int i = 1; i <= v; i++) {
		if (isCutVertex[i])
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	adj = vector<vector<int>>(v + 1);
	discovered = vector<int>(v + 1, -1);
	isCutVertex = vector<bool>(v + 1, false);
	for (int i = 0; i < e; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}

	solve();
	return 0;	
}
