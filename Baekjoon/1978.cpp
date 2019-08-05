#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<bool> prime;

void precalc() {
	prime = vector<bool>(1001, true);
	prime[1] = false;
	for (int i = 2; i*i <= 1001; i++) {
		if (prime[i])
			for (int j = i * i; j <= 1001; j += i) {
				prime[j] = false;
		}
	}
}

int main() {
	cin >> n;
	precalc();
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (prime[tmp])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}