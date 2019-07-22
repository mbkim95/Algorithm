#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int ans, cnt;
bool visited[1000000][11];

void dfs(string s, int depth) {
	if (depth == cnt) {
		int n = stoi(s);
		if (n > ans)
			ans = n;

		return;
	}

	for (int i = 0; i < s.length() - 1; i++) {
		for (int j = i + 1; j < s.length(); j++) {
			swap(s[i], s[j]);
			int temp = stoi(s);
			if (visited[temp][depth + 1] == false) {
				visited[temp][depth + 1] = true;
				dfs(s, depth + 1);
			}
			swap(s[i], s[j]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		ans = 0;
		memset(visited, 0, sizeof(visited));
		string tmp;
		cin >> tmp >> cnt;
		dfs(tmp, 0);
		cout << "#" << c << ' ' << ans << '\n';
	}
}