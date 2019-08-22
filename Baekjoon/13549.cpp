#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int n, k;
vector<bool> visited;

bool inRange(int here) {
	return (0 <= here && here <= 100000);
}

void bfs() {
	if (n == k)
		cout << 0 << '\n';
	else {
		queue<pair<int, int>> q;
		q.push(make_pair(n, 0));
		int ret = INT_MAX;
		int cnt = 0;
		while (!q.empty()) {
			int here = q.front().first;
			int cnt = q.front().second;
			q.pop();
			visited[here] = true;
			if (here == k)
				ret = min(ret, cnt);

			int next = here + 1;
			if (inRange(next) && !visited[next])
				q.push(make_pair(next, cnt + 1));
			next = here - 1;
			if (inRange(next) && !visited[next])
				q.push(make_pair(next, cnt + 1));
			next = 2 * here;
			if (inRange(next) && !visited[next])
				q.push(make_pair(next, cnt));
		}
		cout << ret << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	visited = vector<bool>(200001, false);
	bfs();
	return 0;
}