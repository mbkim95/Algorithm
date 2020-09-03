#include <string>
#include <vector>
using namespace std;

int N, ans;
vector<vector<bool>> map;

bool check(int x, int y) {
    for (int i = 0; i < N; i++) {
        if (i == y) continue;
        if (map[i][x]) return false;
    }

    for (int j = 0; j < N; j++) {
        if (j == x) continue;
        if (map[y][j]) return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == y && j == x) continue;
            if (i + j == x + y && map[i][j]) return false;
            if (j - i == x - y && map[i][j]) return false;
        }
    }
    return true;
}

void dfs(int y) {
    if (y == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        map[y][i] = true;
        if (check(i, y)) dfs(y + 1);
        map[y][i] = false;
    }
}

int solution(int n) {
    N = n;
    map = vector<vector<bool>>(n, vector<bool>(n));
    dfs(0);
    int answer = ans;
    return answer;
}