#include <iostream>
using namespace std;

bool board[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int t = 0; t < 4; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				board[i][j] = true;
	}

	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++)
			if (board[i][j]) answer++;
	}
	cout << answer << '\n';
	return 0;
}