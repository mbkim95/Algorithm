#include <iostream>
#include <queue>
using namespace std;

int N, T, G;
int visited[100000];

int buttonB(int num) {
	int tmp = num/10;
	int i = 1;
	while (tmp > 0) {
		tmp /= 10;
		i *= 10;
	}
	return num - i;
}

int bfs() {
	queue<int>q;
	q.push(N);
	visited[N] = 1;
	int count = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int tmp = q.front(); 
			q.pop();
			if (count > T)
				return -1;
			if (tmp == G)
				return count;
			
			for (int i = 0; i < 2; i++) {
				int num;
				if (i == 0)
					num = tmp + 1;
				else {
					if (2 * tmp > 99999)
						continue;
					num = buttonB(2 * tmp);
				}
				if (0 <= num && !visited[num]) {
					visited[num] = 1;
					q.push(num);
				}
			}
		}
		count++;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T >> G;
	int ans = bfs();
	ans == -1 ? cout << "ANG\n" : cout << ans << '\n';
	return 0;
}