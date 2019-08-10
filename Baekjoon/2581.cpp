#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<bool> prime;

void precalc() {
	prime = vector<bool>(10001, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i*i <= 10000; i++) {
		if (prime[i])
			for (int j = i * i; j <= 10000; j += i)
				prime[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;
	cin >> n;
	int sum = 0;
	int minV = 10000;
	bool find = false;
	precalc();
	for (int i = m; i <= n; i++) {
		if (prime[i]) {
			find = true;
			sum += i;
			minV = min(minV, i);
		}
	}
	if (find)
		cout << sum << '\n' << minV << '\n';
	else
		cout << -1 << '\n';
	return 0;
}