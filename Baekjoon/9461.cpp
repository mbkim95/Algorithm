#include <iostream>
using namespace std;

int n;
long t[101];

int main() {
	int c;
	cin >> c;
	
	t[1] = t[2] = t[3] = 1;
	t[4] = t[5] = 2;

	while (c--) {
		cin >> n;

		for (int i = 6; i <= n; i++) {
			t[i] = t[i - 1] + t[i - 5];
		}

		cout << t[n] << endl;
	}
}