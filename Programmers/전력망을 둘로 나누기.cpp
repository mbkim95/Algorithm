#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int N, m = 0, ans = 987654321;
bool adj[101][101];
int visited[101];

void dfs(int cur) {
    visited[cur] = true;

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && adj[cur][i]) {
            m++;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    for (auto i : wires) {
        N = max(N, max(i[0], i[1]));
        adj[i[0]][i[1]] = true;
        adj[i[1]][i[0]] = true;
    }

    for (auto w : wires) {
        adj[w[0]][w[1]] = false;
        adj[w[1]][w[0]] = false;

        vector<int> tmp = {};

        memset(visited, 0, sizeof(visited));

        for (int i = 1; i <= N; i++) {
            if(!visited[i]) {
                m = 0;
                dfs(i);
                tmp.push_back(m);
            }
        }

        adj[w[0]][w[1]] = true;
        adj[w[1]][w[0]] = true;
        ans = min(ans, abs(tmp[0] - tmp[1]));
    }

    return ans;
}