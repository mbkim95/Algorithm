#include <iostream>
#include <stack>
using namespace std;

void clear(stack<char>& s) {
	while (!s.empty()) s.pop();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char board[8][9];

	for (int t = 1; t <= 1; t++) {
		int ans = 0;
		int size;
		cin >> size;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> board[i][j];
		stack<char> s;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - size; j++) {
				clear(s);
				for (int l = 0; l < size; l++) {
					if (size % 2 == 1) {
						if (l < (size - 1) / 2) s.push(board[i][j + l]);
						else if (l > (size - 1) / 2) {
							if (board[i][j + l] != s.top()) break;
							s.pop();
						}
					}
					else {
						if (l < size / 2) s.push(board[i][j + l]);
						else {
							if (board[i][j + l] != s.top()) break;
							s.pop();
						}
					}
				}
				if (s.empty()) ans++;
			}
		}

		for (int j = 0; j < 8; j++) {
			for (int i = 0; i <= 8 - size; i++) {
				clear(s);
				for (int l = 0; l < size; l++) {
					if (size % 2 == 1) {
						if (l < (size - 1) / 2) s.push(board[i + l][j]);
						else if (l > (size - 1) / 2) {
							if (board[i + l][j] != s.top()) break;
							s.pop();
						}
					}
					else {
						if (l < size / 2) s.push(board[i + l][j]);
						else {
							if (board[i + l][j] != s.top()) break;
							s.pop();
						}
					}
				}
				if (s.empty()) ans++;					
			}
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
	return 0;
}