#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int t[31];
	t[0] = 1;
	t[1] = 0;
	t[2] = 3;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			t[i] = t[i - 2] * t[2];
			for (int j = 4; j <= i; j++)
				t[i] += t[i - j] * 2;
		}
		else
			t[i] = 0;
	}
	cout << t[n] << '\n';
}