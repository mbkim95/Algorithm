#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d, n, m, answer;
vector<int> stones;

void binary_search() {
	int left = 1, right = d;

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		int prev = -1;
		int diff;
		for (int i = 0; i < stones.size(); i++) {
			if (prev == -1)  diff = stones[i];
			else diff = stones[i] - stones[prev];
			
			if (diff < mid) cnt++;
			else prev = i;
		}

		if (cnt > m) right = mid - 1;
		else {
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> d >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		stones.push_back(tmp);
	}
	stones.push_back(d);

	sort(stones.begin(), stones.end());
	binary_search();
	cout << answer << '\n';
	return 0;
}