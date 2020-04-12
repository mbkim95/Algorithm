#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int visited[2][101][101];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

// dir : 0 가로, dir : 1 세로
struct drone {
	int x, y, dir;
};

// 회전시킬 수 있는지 확인
bool canRotate(vector<vector<int>>& board, int x, int y) {
	if (x < 0 || x + 1 > n - 1 || y < 0 || y + 1 > n - 1) return false;
	if (board[y][x] != 0 || board[y][x + 1] != 0 || board[y + 1][x] != 0 || board[y + 1][x + 1] != 0) return false;
	return true;
}

int bfs(vector<vector<int>>& board) {
	n = board.size();
	queue<drone> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		drone cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;
		int dir = cur.dir;

		if (dir == 0 && x + 1 == n - 1 && y == n - 1) return visited[dir][y][x] - 1;
		if (dir == 1 && x == n - 1 && y + 1 == n - 1) return visited[dir][y][x] - 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (dir == 0 && (nx < 0 || nx + 1 > n - 1 || ny < 0 || ny > n - 1)) continue;
			if (dir == 1 && (nx < 0 || nx > n - 1 || ny < 0 || ny + 1 > n - 1)) continue;
			if (dir == 0 && visited[dir][ny][nx] == 0 && board[ny][nx] == 0 && board[ny][nx + 1] == 0) {
				visited[dir][ny][nx] = visited[dir][y][x] + 1;
				q.push({ nx, ny, dir });
			}
			if (dir == 1 && visited[dir][ny][nx] == 0 && board[ny][nx] == 0 && board[ny + 1][nx] == 0) {
				visited[dir][ny][nx] = visited[dir][y][x] + 1;
				q.push({ nx, ny, dir });
			}
		}
		if (dir == 0) {
			// 왼쪽 점을 축으로 위 방향 회전
			if (canRotate(board, x, y - 1) && visited[!dir][y - 1][x] == 0) {
				q.push({ x, y - 1, !dir });
				visited[!dir][y - 1][x] = visited[dir][y][x] + 1;
			}
			// 왼쪽 점을 축으로 아래 방향 회전
			if (canRotate(board, x, y) && visited[!dir][y][x] == 0) {
				q.push({ x, y, !dir });
				visited[!dir][y][x] = visited[dir][y][x] + 1;
			}
			// 오른쪽 점을 축으로 위 방향 회전
			if (canRotate(board, x, y - 1) && visited[!dir][y - 1][x + 1] == 0) {
				q.push({ x + 1, y - 1, !dir });
				visited[!dir][y - 1][x + 1] = visited[dir][y][x] + 1;
			}
			// 오른쪽 점을 축으로 아래 방향 회전
			if (canRotate(board, x, y) && visited[!dir][y][x + 1] == 0) {
				q.push({ x + 1, y, !dir });
				visited[!dir][y][x + 1] = visited[dir][y][x] + 1;
			}
		}
		if (dir == 1) {
			// 위쪽 점을 축으로 왼쪽 방향 회전
			if (canRotate(board, x - 1, y) && visited[!dir][y][x - 1] == 0) {
				q.push({ x - 1, y, !dir });
				visited[!dir][y][x - 1] = visited[dir][y][x] + 1;
			}
			// 위쪽 점을 축으로 오른쪽 방향 회전
			if (canRotate(board, x, y) && visited[!dir][y][x] == 0) {
				q.push({ x, y, !dir });
				visited[!dir][y][x] = visited[dir][y][x] + 1;
			}
			// 아래 점을 축으로 왼쪽 방향 회전
			if (canRotate(board, x - 1, y) && visited[!dir][y + 1][x - 1] == 0) {
				q.push({ x - 1, y + 1, !dir });
				visited[!dir][y + 1][x - 1] = visited[dir][y][x] + 1;
			}
			// 아래 점을 축으로 오른쪽 방향 회전
			if (canRotate(board, x, y) && visited[!dir][y + 1][x] == 0) {
				q.push({ x, y + 1, !dir });
				visited[!dir][y + 1][x] = visited[dir][y][x] + 1;
			}
		}
	}
	return -1;
}

int solution(vector<vector<int>> board) {
	int answer = bfs(board);
	return answer;
}