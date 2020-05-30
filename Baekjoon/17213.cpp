#include <iostream>
using namespace std;

int n, m;
int comb[41][41];

int combination(int a, int b) {
	int& ret = comb[a][b];
	if (ret != -1) return ret;
	if (b == 0 || a == b) return ret = 1;
	return ret = combination(a - 1, b - 1) + combination(a - 1, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= 40; i++) for (int j = 0; j <= 40; j++) comb[i][j] = -1;
	cout << combination(m - 1, m - n) << '\n';
	return 0;
}