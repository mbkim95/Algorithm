#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<bool> prime;

void precalc() {
	prime = vector<bool>(1000001, false);

	for (int i = 2; i <= 1000000; i++)
		prime[i] = true;

	for (int i = 2; i * i <= 1000000; i++)
		if (prime[i])
			for (int j = i * i; j <= 1000000; j += i)
				prime[j] = false;
}

int main() {
	cin >> m >> n;
	precalc();
	for (int i = m; i <= n; i++)
		if (prime[i])
			cout << i << '\n';
	return 0;
}