#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> idx;
	map<string, string> name;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		idx[to_string(i)] = tmp;
		name[tmp] = to_string(i);
	}
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if ('0' <= tmp[0] && tmp[0] <= '9')
			cout << idx[tmp] << '\n';
		else
			cout << name[tmp] << '\n';
	}
	return 0;
}