#include <iostream>
using namespace std;

int v[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v[tmp]++;
	}
	int max_vote = 0;
	int cnt = 0;
	int idx;

	for (int i = 1; i <= n; i++) {
		if (max_vote < v[i]) {
			max_vote = v[i];
			cnt = 1;
			idx = i;
		}
		else if (max_vote == v[i])
			cnt++;
	}
	if (cnt > 1) cout << "skipped\n";
	else cout << idx << '\n';
	return 0;
}