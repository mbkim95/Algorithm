#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		int cnt = 0;
		for (int i = n; i <= m; i++) {
			string num = to_string(i);
			for (int j = 0; j < num.length(); j++)
				if (num[j] == '0') cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}