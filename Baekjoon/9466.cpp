#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
int v[100001];
bool visited[100001], fin[100001];


void dfs(int idx) {
	visited[idx] = true;
	int next = v[idx];
	if (visited[next]) {
		if (!fin[next]) {
			for (int i = next; i != idx; i = v[i])
				ans++;
			ans++;
		}
	}
	else {
		dfs(v[idx]);
	}
	fin[idx] = true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		memset(v, 0, sizeof(v));
		memset(visited, 0, sizeof(visited));
		memset(fin, 0, sizeof(fin));	
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 1; i <= n; i++) {
			if(!visited[i])
				dfs(i);
		}
		cout << n - ans << '\n';
	}
	return 0;
}