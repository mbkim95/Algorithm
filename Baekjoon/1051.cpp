#include <iostream>
using namespace std;

int n, m;
int board[50][50];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &board[i][j]);	

	int size = n < m ? n : m;
	int answer = 0;
	bool flag = false;
	for (int s = size - 1; s >= 0; s--) {
		for (int i = 0; i < n - s; i++) {
			for (int j = 0; j < m - s; j++) {				
				if (board[i][j] == board[i + s][j] && board[i][j] == board[i][j + s] && board[i][j] == board[i + s][j + s]) {
					answer = s + 1;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}
	cout << answer * answer << '\n';
	return 0;
}