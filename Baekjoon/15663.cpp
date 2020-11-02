#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n, m;
int num[10];
bool chk[10];
unordered_set<string> chk_set;

void dfs(int cnt, string s) {
	if (cnt == m) {
		if (chk_set.find(s) == chk_set.end()) {
			cout << s << '\n';
			chk_set.insert(s);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			string tmp = s + to_string(num[i]);
			tmp += ' ';
			chk[i] = true;
			dfs(cnt + 1, tmp);
			chk[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	sort(num, num + n);
	dfs(0, "");
	return 0;
}