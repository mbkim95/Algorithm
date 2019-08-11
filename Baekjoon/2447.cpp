#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> star;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << star[i][j];
		cout << '\n';
	}
}

void drawStar(int x, int y, int size) {
	if (size == 1) {
		star[y][x] = '*';
		return;
	}
	drawStar(x + size / 3 * 0, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 1, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 0, y + size / 3 * 1, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 1, size / 3);
	drawStar(x + size / 3 * 0, y + size / 3 * 2, size / 3);
	drawStar(x + size / 3 * 1, y + size / 3 * 2, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 2, size / 3);
}

void solve(int x, int y, int size) {
	drawStar(x + size / 3 * 0, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 1, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 0, size / 3);
	drawStar(x + size / 3 * 0, y + size / 3 * 1, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 1, size / 3);
	drawStar(x + size / 3 * 0, y + size / 3 * 2, size / 3);
	drawStar(x + size / 3 * 1, y + size / 3 * 2, size / 3);
	drawStar(x + size / 3 * 2, y + size / 3 * 2, size / 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	star = vector<vector<char>>(n, vector<char>(n, ' '));
	solve(0, 0, n);
	print();
}