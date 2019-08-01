#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> a, b;

int main() {
	cin >> n;
	a = vector<int>(n);
	b = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans << '\n';
	return 0;
}
