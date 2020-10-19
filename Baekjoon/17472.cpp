#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, m;
int parent[7];
int board[11][11];
int visited[11][11];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
vector<pair<int, pair<int, int>>> edges; // 섬들 사이의 거리 저장 vector
set<pair<int, pair<int, int>>> s; // 섬들 사이에 중복되는 경로를 제거하기위한 set

// 섬들을 구분하기 위해 bfs 알고리즘 사용
void bfs(int x, int y, int idx) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = idx;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위를 벗어나는 경우
			// 방문한 적 없고 육지인 경우
			if (!visited[ny][nx] && board[ny][nx] == board[cur.second][cur.first]) {
				q.push({ nx, ny });
				visited[ny][nx] = idx;
			}
		}
	}
}

void calculate_distance(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int dist = 0;
		int nx = x;
		int ny = y;
		int idx = visited[y][x];
		while (true) {
			nx += dx[i];
			ny += dy[i];
			int next_idx = visited[ny][nx];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || next_idx == idx) break;
			if (next_idx != 0 && next_idx != idx) {
				if (idx > next_idx) swap(idx, next_idx); // 섬은 작은 번호부터 큰 번호 순으로 저장
				// 다리 길이가 1보다 길면 저장
				if (dist > 1) s.insert({ dist, {idx, next_idx} });
				break;
			}
			else dist++;
		}
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int kruskal() {
	sort(edges.begin(), edges.end());

	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		int land1 = edges[i].second.first;
		int land2 = edges[i].second.second;
		int dist = edges[i].first;
		if (find(land1) == find(land2)) continue;
		merge(land1, land2);
		sum += dist;
	}
	return sum;
}

bool is_all_connected(int idx) {
	int p = find(1);
	for (int i = 2; i <= idx; i++)
		if (p != find(i)) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	// 섬 라벨링
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j] != 0) {
				bfs(j, i, ++idx);
			}
		}
	}

	// 유니온 파인드 초기 부모 설정
	for (int i = 1; i <= idx; i++) parent[i] = i;

	// 섬들 사이의 거리 저장
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			// 라벨링 된 곳에서 시작한다
			if (visited[i][j] != 0)
				calculate_distance(j, i);

	// 중복 제거한 섬들 사이의 거리를 edges에 저장
	for (auto i : s) edges.push_back(i);

	int answer = kruskal();

	// 모든 섬이 연결되어있으면 건설 비용 출력
	if (is_all_connected(idx)) cout << answer << '\n';
	// 모든 섬을 연결할 수 없으면 -1 출력
	else cout << "-1\n";
	return 0;
}