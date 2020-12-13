#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 50001;
const int BIT = 17;

int n, m;
int h[MAX_N];
int parent[MAX_N][BIT];
vector<int> adj[MAX_N];

void make_tree(int idx) {
	for (int next : adj[idx]) {
		if (h[next] == -1) {
			parent[next][0] = idx;
			h[next] = h[idx] + 1;
			make_tree(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	memset(h, -1, sizeof(h));
	h[1] = 0;
	make_tree(1);

	for (int j = 0; j < BIT - 1; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j + 1] = parent[parent[i][j]][j];

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (h[a] < h[b]) swap(a, b);
		
		int diff = h[a] - h[b];
		
		for (int i = BIT - 1; i >= 0; i--) {
			if (diff >= (1 << i)) {
				diff -= (1 << i);
				a = parent[a][i];
			}
		}

		if (a != b) {
			for (int j = BIT - 1; j >= 0; j--) {
				if (parent[a][j] != parent[b][j]) {
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			a = parent[a][0];
		}
		cout << a << '\n';
	}
	return 0;
}