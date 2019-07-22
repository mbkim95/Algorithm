#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int box[100];

pair<int, int> findMaxMin() {
	int minIdx = 0;
	int maxIdx = 0;
	for (int i = 0; i < 100; i++) {
		if (box[minIdx] > box[i])
			minIdx = i;
		if (box[maxIdx] < box[i])
			maxIdx = i;
	}
	return make_pair(maxIdx, minIdx);
}

int solve() {
	int ans = 0;
	pair<int, int> idx;
	for (int i = 0; i < cnt; i++) {
		idx = findMaxMin();
		box[idx.first]--;
		box[idx.second]++;
	}
	idx = findMaxMin();
	ans = box[idx.first] - box[idx.second];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int t = 1; t <= 10; t++) {
		cin >> cnt;
		for (int i = 0; i < 100; i++)
			cin >> box[i];
		cout << "#" << t << ' ' << solve() << '\n';
	}
	return 0;
}