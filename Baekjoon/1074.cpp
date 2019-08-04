#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c;
int result;

void recursion(int x, int y, int len) {
	if (x == c && y == r) {
		cout << result << endl;
		exit(0);
	}

	if (len == 1) {
		result++;
		return;
	}

	if (!(x <= c && c < x + len && y <= r && r < y + len)) {
		result += len * len;
		return;
	}
	recursion(x, y, len / 2);
	recursion(x + len / 2, y, len / 2);
	recursion(x, y + len / 2, len / 2);
	recursion(x + len / 2, y + len / 2, len / 2);
}

int main() {
	cin >> n >> r >> c;
	recursion(0, 0, pow(2, n));
	return 0;
}
