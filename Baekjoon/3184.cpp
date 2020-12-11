#include <iostream>
#include <queue>
using namespace std;

int r, c;
char board[251][251];
bool visited[251][251];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

pair<int, int> bfs(int x, int y) {
    int sheep = 0, wolf = 0;
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    if (board[y][x] == 'o') sheep++;
    else if (board[y][x] == 'v') wolf++;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx > c - 1 || ny < 0 || ny > r - 1) continue;

            if (board[ny][nx] != '#' && !visited[ny][nx]) {
                q.push({nx, ny});
                if (board[ny][nx] == 'o') sheep++;
                else if (board[ny][nx] == 'v') wolf++;
                visited[ny][nx] = true;
            }
        }
    }
    if (sheep > wolf) return {sheep, 0};
    else return {0, wolf};
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    int sheep = 0, wolf = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j]) {
                pair<int, int> result = bfs(j, i);
                sheep += result.first;
                wolf += result.second;
            }
        }
    }
    cout << sheep << ' ' << wolf << '\n';
    return 0;
}
