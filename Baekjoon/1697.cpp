#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001];

int bfs() {
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	int time = 0;
	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int tmp = q.front();
			q.pop();

			if (tmp == k)
				return time;

			for (int i = 0; i < 3; i++) {
				int move;
				if (i == 0)
					move = tmp - 1;
				else if (i == 1)
					move = tmp + 1;
				else
					move = 2 * tmp;

				

				if (0 <= move && move <= 100000 && !visited[move]) {
					q.push(move);
					visited[move] = 1;
				}
			}
		}
		time++;
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	cout << bfs() << '\n';
	return 0;
}