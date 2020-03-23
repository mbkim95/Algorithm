#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

void dfs(int cnt, int tmp) {
	if (cnt == 7)
		return;
	num.push_back(tmp);
	dfs(cnt + 1, tmp * 10 + 4);
	dfs(cnt + 1, tmp * 10 + 7);
}

int main() {
	dfs(0, 0);
	sort(num.begin(), num.end());
	int n;
	cin >> n;
	int idx = 0;
	bool find = false;
	while (true) {
		if (idx == num.size()) 
			break;

		if (num[idx] > n) {
			find = true;
			break;
		}
		idx++;
	}

	if (find && idx > 0)
		cout << num[idx - 1] << '\n';
	else if (!find)
		cout << num[num.size() - 1] << '\n';
	return 0;
}