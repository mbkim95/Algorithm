#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	long long sum = 0;
	for (long long i = 1; i < n; i++) {
		sum += (long long)(i * n + i);
	}
	cout << sum << '\n';
	return 0;
}