#include <iostream>
#include <algorithm>
using namespace std;

int n, p[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);

	int sum = 0;
	for (int i = 0; i < n; i++) sum += p[i] * (n - i);
	cout << sum << '\n';
	return 0;
}
