#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> root, power;

int find(int x) {
	if (root[x] != x)
		root[x] = find(root[x]);
	return root[x];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) {
		root[b] = a;
		power[a] += power[b];
	}
	else {
		root[a] = b;
		power[b] += power[a];
	}
}

void fight(int a, int b) {
	a = find(a);
	b = find(b);

	if (power[a] > power[b]) {
		power[a] -= power[b];
		root[b] = a;
	}
	else if (power[a] < power[b]) {
		power[b] -= power[a];
		root[a] = b;
	}
	else {
		root[a] = 0;
		root[b] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	root = vector<int>(n + 1);
	power = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> power[i];

	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 0; i < m; i++) {
		int o, p, q;
		cin >> o >> p >> q;
		if (o == 1) merge(p, q);
		else fight(p, q);
	}

	set<int> s;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int p = find(i);
		if (p != 0)
			s.insert(p);
	}
	for (int i : s)
		ans.push_back(power[i]);
	
	sort(ans.begin(), ans.end());
	cout << s.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
	return 0;
}