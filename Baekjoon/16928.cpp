#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m;
map<int, int> ladder, snake;

int bfs() {
    queue<pair<int, int>> q;
    bool visited[101];
    for(int i=1; i<=100; i++) visited[i] = false;

    q.push({1, 0});
    visited[1] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.first == 100) return cur.second;

        for(int i=1; i<=6; i++) {
            int next = cur.first + i;
            int cnt = cur.second + 1;
            if(ladder.count(next) > 0) next = ladder[next];
            else if(snake.count(next) > 0) next = snake[next];

            if(next <= 100 && !visited[next]) {
                q.push({next, cnt});
                visited[next] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) { 
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }
    cout << bfs() << '\n';
    return 0;
}