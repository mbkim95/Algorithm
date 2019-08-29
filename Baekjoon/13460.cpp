#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, Rx, Ry, Bx, By;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0 ,1 };

int bfs(vector<vector<char>>& map) {
	bool visited[10][10][10][10] = { 0, };
	queue <pair<pair<int, int>, pair<int, int>>> q;
	visited[Rx][Ry][Bx][By] = true;
	q.push(make_pair(make_pair(Rx, Ry), make_pair(Bx, By)));
	int cnt = 0;
	while (!q.empty()) {
		if (cnt > 10) break;
		int size = q.size();
		while (size--) {
			pair<pair<int, int>, pair<int, int>> cur = q.front();
			q.pop();
			int rx = cur.first.first;
			int ry = cur.first.second;
			int bx = cur.second.first;
			int by = cur.second.second;

			if (map[ry][rx] == 'O' && map[by][bx] != 'O')
				return cnt;

			for (int i = 0; i < 4; i++) {
				int nrx = rx;
				int nry = ry;
				int nbx = bx;
				int nby = by;

				while (true) {
					if (map[nry][nrx] != '#' && map[nry][nrx] != 'O') {
						nrx += dx[i];
						nry += dy[i];
					}
					else {
						if (map[nry][nrx] == '#') 
							nrx -= dx[i], nry -= dy[i];
						break;
					}
				}

				while (true) {
					if (map[nby][nbx] != '#' && map[nby][nbx] != 'O') {
						nbx += dx[i];
						nby += dy[i];
					}
					else {
						if (map[nby][nbx] == '#')
							nbx -= dx[i], nby -= dy[i];
						break;
					}
				}

				if (nrx == nbx && nry == nby) {
					if (map[nry][nrx] != 'O') {
						int rmove = abs(nrx - rx) + abs(nry - ry), bmove = abs(nbx - bx) + abs(nby - by);
						if (rmove > bmove) nrx -= dx[i], nry -= dy[i];
						else nbx -= dx[i], nby -= dy[i];
					}
				}

				if (!visited[nrx][nry][nbx][nby]) {
					visited[nrx][nry][nbx][nby] = true;
					q.push(make_pair(make_pair(nrx, nry), make_pair(nbx, nby)));
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				Rx = j;
				Ry = i;
			}
			else if (map[i][j] == 'B') {
				Bx = j;
				By = i;
			}
		}
	cout << bfs(map) << '\n';
	return 0;
}