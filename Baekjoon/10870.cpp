#include <iostream>
#include <functional>
using namespace std;

int main() {
	int n;
	cin >> n;

	function<int(int n)> fib = [&](int n) {
		if (n <= 1)
			return n;		
		return fib(n - 1) +fib(n - 2);
	};
	cout << fib(n) << '\n';
}