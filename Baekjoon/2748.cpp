#include <iostream>
using namespace std;

int n;
long long fib[91];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[n] << '\n';
	return 0;
}
