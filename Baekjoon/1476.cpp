#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int ans = 1;
	int n1 = 1, n2 = 1, n3 = 1;

	while (n1 != e || n2 != s || n3 != m) {
		n1++;
		n2++;
		n3++;
		if (n1 == 16) n1 = 1;
		if (n2 == 29) n2 = 1;
		if (n3 == 20) n3 = 1;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}