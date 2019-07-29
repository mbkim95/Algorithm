#include <iostream>
using namespace std;

int x;
const int cand[] = { 64, 32, 16, 8, 4, 2, 1 };

int main() {
	cin >> x;

	int cnt = 0;

	for (int i = 0; i < 7; i++) {
		if (x == 0)
			break;
		if (x >= cand[i]) {
			x -= cand[i];
			cnt++;
		}
	}
	cout << cnt << '\n';
}