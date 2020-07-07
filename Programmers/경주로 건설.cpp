#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
    int x, y, dir;
};

// (j, i) 에서의 최소값을 담을 배열
int chk[25][25][4];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

int bfs(const vector<vector<int>>& board, const int n) {
    queue<pos> q;
    for (int i = 0; i < 4; i++) {
        q.push({ 0, 0, i });
        chk[0][0][i] = 0;
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().dir;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if (board[ny][nx] == 1) continue;
            // 직선 도로를 만들 때
            if (d == i) {
                // 아직 방문한 적 없는 지점이거나 최솟값을 갱신할 수 있을 때
                if (chk[ny][nx][d] == -1 || chk[ny][nx][d] > chk[y][x][d] + 100) {
                    chk[ny][nx][d] = chk[y][x][d] + 100;
                    q.push({ nx, ny, d });
                }
            }
            // 코너를 만들 때
            else {
                // 아직 방문한 적 없는 지점이거나 최솟값을 갱신할 수 있을 때
                if (chk[ny][nx][i] == -1 || chk[ny][nx][i] > chk[y][x][d] + 600) {
                    chk[ny][nx][i] = chk[y][x][d] + 600;
                    q.push({ nx, ny, i });
                }
            }
        }
    }
    int ans = 987654321;
   // 목적지의 네 방향을 확인했을 때 최솟값이 정답이 된다
    for (int i = 0; i < 4; i++) {
        if (chk[n - 1][n - 1][i] == -1) continue;
        ans = min(ans, chk[n - 1][n - 1][i]);
    }
    return ans;
}

int solution(vector<vector<int>> board) {
    int size = board.size();
    // 방문하지 않는 곳을 확인하기 위해 -1로 초기화
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int l = 0; l < 4; l++)
                chk[i][j][l] = -1;

    int answer = bfs(board, size);
    return answer;
}