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

void draw_star(int x, int y, int size) {
	if (size == 1) {
		star[y][x] = '*';
		return;
	}
	draw_star(x + size / 3 * 0, y + size / 3 * 0, size / 3);
	draw_star(x + size / 3 * 1, y + size / 3 * 0, size / 3);
	draw_star(x + size / 3 * 2, y + size / 3 * 0, size / 3);
	draw_star(x + size / 3 * 0, y + size / 3 * 1, size / 3);
	draw_star(x + size / 3 * 2, y + size / 3 * 1, size / 3);
	draw_star(x + size / 3 * 0, y + size / 3 * 2, size / 3);
	draw_star(x + size / 3 * 1, y + size / 3 * 2, size / 3);
	draw_star(x + size / 3 * 2, y + size / 3 * 2, size / 3);
}

int main() {
	cin >> n;
	star = vector<vector<char>>(n, vector<char>(n, ' '));
	draw_star(0, 0, n);
	print();
}
