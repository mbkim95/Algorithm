#include <iostream>
#include <vector>
using namespace std;

vector<long long> fib;

long long fibonacci(int n) {
	long long& ret = fib[n];
	if (ret != -1) return ret;
	if (n < 2) return ret = 1;
	if (n == 2) return ret = 2;
	if (n == 3) return ret = 4;
	else return ret = fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3) + fibonacci(n - 4);
}

int main() {
	int t;
	cin >> t;
	fib = vector<long long>(68, -1);
	while (t--) {
		int n;
		cin >> n;
		cout << fibonacci(n) << '\n';
	}
	return 0;
}