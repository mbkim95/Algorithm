#include <iostream>
using namespace std;

bool canFind;
int r, c, b[5][5];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt, int ate) {
    if(canFind || cnt > 3) return;

    if(ate >= 2) {
        canFind = true;
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx > 4 || ny < 0 || ny > 4 || b[ny][nx] == -1) continue;

        int prev = b[y][x];
        b[y][x] = -1;
        if(b[ny][nx] == 1) dfs(nx, ny, cnt+1, ate+1);
        else if(b[ny][nx] == 0) dfs(nx, ny, cnt+1, ate);
        b[y][x] = prev;
    }
}

int main() {
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) cin >> b[i][j];
    cin >> r >> c;
    dfs(c, r, 0, b[r][c] == 1 ? 1 : 0);
    cout << (canFind ? 1 : 0) << '\n';
    return 0;
}