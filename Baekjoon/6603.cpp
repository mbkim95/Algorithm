#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int>& v, vector<int>& picked, int idx, int k) {
	if (picked.size() == 6) {
		for(int i=0; i<6; i++)
			cout << picked[i] << ' ';	
		cout << '\n';
		return;
	}

	if (idx >= k)
		return;

	picked.push_back(v[idx]);
	solve(v, picked, idx + 1, k);
	picked.pop_back();
	solve(v, picked, idx + 1, k);
}

int main() {
	while (1) {
		int k;
		cin >> k;
		vector<int> v(k, 0);
		vector<int> picked;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}
		solve(v, picked, 0, k);
		cout << '\n';
	}

	return 0;
}