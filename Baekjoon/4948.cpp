#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<bool> prime;

void precalc() {
	prime[0] = prime[1] = false;
	int limit = 2 * 123456;
	for (int i = 2; i*i <= limit; i++) {
		if (prime[i])
			for (int j = i * i; j <= limit; j+=i)
				prime[j] = false;
	}
}

int solve(int n) {
	int ret = 0;
	for (int i = n + 1; i <= 2 * n; i++){
		if (prime[i])
			ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime = vector<bool>(2 * 123456 + 1, true);
	precalc();
	while (true) {
		int c;
		cin >> c;
		if (c == 0)
			break;
		cout << solve(c) << '\n';
	}
	return 0;
}