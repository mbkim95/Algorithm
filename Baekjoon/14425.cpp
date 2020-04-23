#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> map;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		map[tmp] = 1;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if (map.count(tmp) > 0) ans++;
	}
	cout << ans << '\n';
	return 0;
}