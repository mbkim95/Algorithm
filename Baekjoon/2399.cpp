#include <iostream>
#include <algorithm>
using namespace std;

long long num[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (num[i] * (2 * i - n + 1));			
	cout << 2 * ans << '\n';
	return 0;
}