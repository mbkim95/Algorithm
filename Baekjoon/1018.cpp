#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char b1[8][9], b2[51][51];

int countRow(char base, int col) {        // �� ���� �߸��� ������ ������ ��
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		if (base != b1[col][i])
			cnt++;

		if (base == 'W')
			base = 'B';
		else
			base = 'W';
	}
	return cnt;
}

int countAll(char start) {        // ��� ĭ�� �߸��� ������ ������ ��
	int ret = 0;

	for (int i = 0; i < 8; i++) {
		ret += countRow(start, i);
		if (start == 'W')
			start = 'B';
		else
			start = 'W';
	}
	return ret;
}

void cutBoard(int startCol, int startRow) {        // 8x8�� ü�������� �ڸ��� �Լ�
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			b1[i][j] = b2[i + startCol][j + startRow];
		}
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << b1[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int solve() {
	int ret = 64;

	int a = n - 8, b = m - 8;

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			cutBoard(i, j);
			//	print();
			ret = min(min(ret, countAll('W')), countAll('B'));
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b2[i][j];
		}
	}
	cout << solve() << '\n';

	return 0;
}