#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) cnt = 1;
		else ans += cnt++;
	}
	cout << ans << '\n';
	return 0;
}