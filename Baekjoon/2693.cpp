#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int num[10];
		for (int i = 0; i < 10; i++)
			cin >> num[i];
		sort(num, num + 10);
		cout << num[7] << '\n';
	}
	return 0;
}