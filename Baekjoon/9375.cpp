#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int t;
	cin >> t;
	while (t--) {
		map<string, int> clothes;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			clothes[str2]++;
		}

		int ans = 1;
		for (auto it : clothes) {
			ans *= (it.second + 1);
		}
		cout << ans - 1 << '\n';
	}
}