#include <iostream>
using namespace std;

int n, w, b;
int paper[128][128];

void countPaper(int sx, int sy, int h) {
	int c = paper[sy][sx];

	bool find = true;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < h; j++)
			if (c != paper[sy + i][sx + j]) {
				find = false;
				break;
			}
	if (find) {
		if (c == 0) w++;
		else b++;
		return;
	}

	countPaper(sx, sy, h / 2);
	countPaper(sx + h / 2, sy, h / 2);
	countPaper(sx, sy + h / 2, h / 2);
	countPaper(sx + h / 2, sy + h / 2, h / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	countPaper(0, 0, n);
	cout << w << '\n' << b << '\n';
	return 0;
}