#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

struct Point {
	int x, y, z, cnt;
};

int n, ans = INT_MAX;
int board[5][5][5];
int buff[5][5][5];
bool visited[5][5][5];
const int dx[] = { 0, 1, 0, -1, 0, 0 }, dy[] = { -1, 0, 1, 0, 0, 0 }, dz[] = { 0, 0, 0, 0, 1, -1 };

void rotate_board(int idx) {
	int tmp[5][5];
	memcpy(tmp, board[idx], sizeof(tmp));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			board[idx][i][j] = tmp[n - 1 - j][i];
}

int bfs() {
	memset(visited, false, sizeof(visited));
	queue<Point> q;
	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = true;


	while (!q.empty()) {
		Point cur = q.front();
		int cnt = cur.cnt;
		if (cur.x == 4 && cur.y == 4 && cur.z == 4) return cnt;
		if (cnt >= ans) return INT_MAX;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i]; int ny = cur.y + dy[i]; int nz = cur.z + dz[i];
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || nz < 0 || nz > 4) continue;
			if (!visited[nz][ny][nx] && board[nz][ny][nx]) {
				q.push({ nx, ny, nz, cnt + 1 });
				visited[nz][ny][nx] = true;
			}
		}
	}
	return INT_MAX;
}

void shuffle() {
	int h[] = { 0, 1, 2, 3, 4 };
	// 쌓는 순서를 조합을 사용해서 결정
	do {
		// board에 면들을 쌓아서 저장
		for (int i = 0; i < 5; i++) memcpy(board[h[i]], buff[i], sizeof(buff[i]));

		// 맨 윗층부터 돌린다
		for (int i = 0; i < 4; i++) {
			rotate_board(0);
			// 출발점이 이동 불가능한 경우를 건너뛰어 최적화해준다
			if (!board[0][0][0]) continue;
			for (int j = 0; j < 4; j++) {
				rotate_board(1);
				for (int k = 0; k < 4; k++) {
					rotate_board(2);
					for (int l = 0; l < 4; l++) {
						rotate_board(3);
						for (int m = 0; m < 4; m++){
							rotate_board(4);
							ans = min(ans, bfs());
							// 12보다 더 작은 답이 나올 수 없으므로 프로그램 종료
							if (ans == 12) {
								cout << ans << '\n';
								exit(0);
							}
						}
					}
				}
			}
		}		
	} while (next_permutation(h, h + 5));
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	n = 5;
	for (int l = 0; l < 5; l++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> buff[l][i][j];
	shuffle();
	return 0;
}