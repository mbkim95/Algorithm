#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int s = 0, e = 0;
	cin >> n >> m;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int ans = 0;
	int sum = 0;
	while (true) {
		if (sum >= m) sum -= num[s++];
		else if (e == n) break;
		else sum += num[e++];
		if (sum == m) ans++;
	}
	cout << ans << '\n';
	return 0;
}