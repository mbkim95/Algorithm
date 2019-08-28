#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;

void rotateBoard(vector<vector<int>>& board) {
	vector<vector<int>> tmp = board;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = tmp[n - 1 - j][i];
}

void up(vector<vector<int>>& board) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {			
			if (!board[i][j]) {
				int l;
				for (int l = i + 1; l < n; l++) {
					if (board[l][j]) {
						int k;
						int value = board[l][j];
						for (int k = l + 1; k < n; k++) {
							if (board[k][j]) {
								if (value == board[k][j]) {
									board[l][j] *= 2;
									board[k][j] = 0;
									ans = max(ans, board[l][j]);
								}
								break;
							}
						}
						board[i][j] = board[l][j];
						board[l][j] = 0;
						break;
					}
				}
			}
			else {
				int l;
				int value = board[i][j];
				for (int l = i + 1; l < n; l++) {
					if (board[l][j]) {
						if (value == board[l][j]) {
							board[i][j] *= 2;
							board[l][j] = 0;
							ans = max(ans, board[i][j]);
						}
						break;
					}
				}
			}
		}
	}
}

void right(vector<vector<int>>& board) {
	for (int i = 0; i < 3; i++) rotateBoard(board);
	up(board);
	rotateBoard(board);
}

void down(vector<vector<int>>& board) {
	for (int i = 0; i < 2; i++) rotateBoard(board);
	up(board);
	for (int i = 0; i < 2; i++) rotateBoard(board);
}

void left(vector<vector<int>>& board) {
	rotateBoard(board);
	up(board);
	for (int i = 0; i < 3; i++) rotateBoard(board);
}

void dfs(vector<vector<int>>& board, vector<int>& op, int cnt) {
	if (cnt == 5) {
		vector<vector<int>> tmp = board;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 0)	up(tmp);
			else if (op[i] == 1) right(tmp);
			else if (op[i] == 2) down(tmp);
			else left(tmp);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		op.push_back(i);
		dfs(board, op, cnt + 1);
		op.pop_back();
	}
}

void solve(vector<vector<int>>& board) {
	vector<int> op;
	dfs(board, op, 0);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			ans = max(ans, board[i][j]);
		}
	solve(board);
	return 0;
}