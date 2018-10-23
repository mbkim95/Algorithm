#include <iostream>
#include <algorithm>
using namespace std;

int n;
char b[50][50];

void swap(int x1, int y1, int x2, int y2) {
	char tmp = b[y1][x1];
	b[y1][x1] = b[y2][x2];
	b[y2][x2] = tmp;
}

int count(int x, int y) {
	int tmp1 = 1, tmp2 = 1;
	char cmp = b[y][x];

	for (int i = y + 1; i < n; i++) {
		if (cmp != b[i][x])
			break;
		tmp1++;
	}

	for (int i = x + 1; i < n; i++) {
		if (cmp != b[y][i])
			break;
		tmp2++;
	}

	return tmp1 > tmp2 ? tmp1 : tmp2;
}

int countAll() {
	int ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, count(j, i));

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(j, i, j + 1, i);
			ans = max(ans, countAll());
			swap(j, i, j + 1, i);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			swap(j, i, j, i + 1);
			ans = max(ans, countAll());
			swap(j, i, j, i + 1);
		}
	}
	cout << ans << '\n';

	return 0;
}