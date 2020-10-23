#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

bool p[10000];
unordered_set<int> prime;

void pre_calc() {
	fill(p, p + 10000, true);
	for (int i = 2; i <= 9999; i++) {
		if (p[i]) {
			int j = 2;
			while (i * j <= 9999) {
				p[i * j] = false;
				j++;
			}
		}
	}
	for (int i = 1000; i <= 9999; i++)
		if (p[i])
			prime.insert(i);
}

int bfs(int start, int end) {
	queue<int> q;
	vector<int> visited(9999, 0);
	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == end) return visited[end] - 1;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				string next = to_string(cur);
				if (i == 0 && j == 0 || next[i] == ('0' + j)) continue;
				next[i] = '0' + j;
				int next_num = stoi(next);
				if (prime.find(next_num) != prime.end() && !visited[next_num]) {
					visited[next_num] = visited[cur] + 1;
					q.push(next_num);
				}
			}
		}
	}
	return -1;
}

int main() {	
	int t;
	cin >> t;
	pre_calc();
	while (t--) {
		int start, end;
		cin >> start >> end;
		int ans = bfs(start, end);
		if (ans == -1) cout << "Impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}