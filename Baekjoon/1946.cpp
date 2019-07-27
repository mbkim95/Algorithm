#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<pair<int, int>> score;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		score = vector<pair<int, int>>(n);
		for (int i = 0; i < n; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			score[i] = make_pair(tmp1, tmp2);
		}
		sort(score.begin(), score.end());
		
		int tmp = score[0].second;
		ans = 1;
		for (int i = 0; i < n; i++) {
			if (tmp > score[i].second) {
				tmp = score[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}