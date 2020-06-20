#include <iostream>
#include <algorithm>
using namespace std;

int ans, mush[10];

void dfs(int idx, int score) {
	if (idx == 10) {
		if (abs(100 - score) < abs(100 - ans)) ans = score;
		else if (abs(100 - score) == abs(100 - ans)) ans = max(ans, score);
		return;
	}

	dfs(idx + 1, score + mush[idx]);
	dfs(10, score);
}

int main() {
	for (int i = 0; i < 10; i++)
		cin >> mush[i];
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}