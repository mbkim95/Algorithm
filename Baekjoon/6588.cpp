#include <iostream>
#include <algorithm>
using namespace std;

bool chk[1000001];

void precalc() {
	fill(chk, chk + 1000001, true);
	chk[1] = false;
	for (int i = 1; i * i <= 1000000; i++) {
		if (!chk[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) 
			chk[j] = false;		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	precalc();
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		bool find = false;
		for (int i = 3; i < n; i += 2) {
			if (chk[i] && chk[n - i]) {
				find = true;
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
		if (!find) cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}