#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[1001][1001];

int main() {

	bool all_zero = true;
	int answer = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			if (all_zero && board[i][j] == 1) {
				answer = 1;
				all_zero = false;
			}
		}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] != 0) {
				board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
				answer = max(answer, board[i][j]);
			}
		}
	}
	printf("%d\n", answer * answer);
	return 0;
}