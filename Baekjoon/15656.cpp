#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num[8];
vector<int> ans;

void dfs(int idx) {
	if (ans.size() == m) {
		for (int i : ans)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		ans.push_back(num[i]);
		dfs(i);
		ans.pop_back(); 
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	dfs(0);
	return 0;
}