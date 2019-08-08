#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<bool> prime;
vector<int> v;

void precalc() {
	prime = vector<bool>(10001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= 10000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 10000; j += i)
				prime[j] = false;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (prime[i])
			v.push_back(i);
	}
}

void solve() {
	int diff = n;
	int a, b;
	for (int i = 0; i < v.size(); i++) {
		if (binary_search(v.begin(), v.end(), n - v[i])) {
			if (diff > abs(n - v[i] * 2)) {
				diff = abs(n - v[i] * 2);
				a = v[i];
				b = n - v[i];
			}
		}
	}
	if (a > b) {
		int tmp = b;
		b = a;
		a = tmp;
	}
	cout << a << ' ' << b << '\n';
}

int main() {
	int t;
	cin >> t;
	precalc();
	while (t--) {
		cin >> n;
		solve();
	}
	return 0;
}