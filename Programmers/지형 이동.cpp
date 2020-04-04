#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n, h, num, ans = INT_MAX;
vector<int> parent, size;
vector<vector<int>> visited;
vector<bool> chk;
vector<pair<int, pair<int, int>>> edges;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    if (size[u] == size[v]) size[u]++;
}

int kruskal() {
    int cnt = 1;
    int ret = 0;    

    // 최소 비용의 사다리부터 설치할 수 있도록 정렬
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (find(a) == find(b)) continue;
        merge(a, b);
        ret += cost;
        // 모든 그룹이 연결된 경우 반복문을 중지
        if (++cnt == num) break;
    }
    return ret;
}

// 그룹 간 이동할 때 필요한 비용을 저장
void getCost(vector<vector<int>>& land) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[y][x] == visited[ny][nx]) continue;
                // 사다리를 설치해야하는 경우를 모두 저장
                edges.push_back({ abs(land[y][x] - land[ny][nx]), {visited[y][x], visited[ny][nx]} });
            }
        }
    }
}

// BFS를 해서 그룹을 분류
void bfs(int x, int y, int num, vector<vector<int>>& land) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[y][x] = num;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[ny][nx] || abs(land[cur.second][cur.first] - land[ny][nx]) > h) continue;
            visited[ny][nx] = num;
            q.push({ nx, ny });
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    n = land.size();
    h = height;

    // 그룹 분류
    visited = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) bfs(j, i, ++num, land);

    chk = vector<bool>(num, false);
    parent = vector<int>(num + 1);
    size = vector<int>(num + 1, 0);

    // 사다리를 놓아야 하는 경우에 필요한 비용을 저장
    getCost(land);

    for (int i = 1; i <= num; i++) parent[i] = i;

    // Kruskal 알고리즘을 통해 MST생성 및 결과 반환
    answer = kruskal();
    return answer;
}