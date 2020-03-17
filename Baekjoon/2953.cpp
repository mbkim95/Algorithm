#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= 5; i++) {
		int score = 0;
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			score += tmp;
		}
		pq.push({ score, i });
	}
	cout << pq.top().second << ' ' << pq.top().first << '\n';
	return 0;
}