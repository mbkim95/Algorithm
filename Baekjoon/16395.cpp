#include <iostream>
using namespace std;

int n, k;
int c[30][30];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= i - 1; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	cout << c[n - 1][k - 1] << '\n';
	return 0;
}