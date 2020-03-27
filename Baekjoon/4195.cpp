#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int idx = 0;
map<string, int> name;
vector<int> parent, num;
vector<pair<string, string>> cmd;

void setting() {
	parent = vector<int>(idx);
	num = vector<int>(idx, 1);
	for (int i = 0; i < idx; i++)
		parent[i] = i;
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u != v) {
		parent[u] = v;
		num[v] += num[u];
		num[u] = 1;
	}
	return num[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		name = map<string, int>();
		cmd.clear();
		idx = 0;
		for (int i = 0; i < f; i++) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			cmd.push_back({ tmp1, tmp2 });
			if (name.find(tmp1) == name.end()) name[tmp1] = idx++;
			if (name.find(tmp2) == name.end()) name[tmp2] = idx++;
		}
				 
		setting();

		for (int i = 0; i < cmd.size(); i++) {
			string p1 = cmd[i].first;
			string p2 = cmd[i].second;
			int idx1 = name[p1];
			int idx2 = name[p2];
			cout << merge(idx1, idx2) << '\n';
		}
	}
	return 0;
}