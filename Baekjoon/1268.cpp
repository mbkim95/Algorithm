#include <iostream>
#include <set>
#include <vector>
using namespace std;

int s[1001][6];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++)
			cin >> s[i][j];
	}
	vector<set<int>> v(n + 1);

	for (int student = 1; student <= n; student++) {
		for (int j = 1; j <= 5; j++) {	
			int class_num = s[student][j];
			for (int i = 1; i <= n; i++) {
				if (student == i) continue;
				if (class_num == s[i][j]) v[student].insert(i);
			}
		}
	}

	int max = 0;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (max < v[i].size()) {
			max = v[i].size();
			ans = i;
		}
	}
	cout << ans << '\n';
	return 0;
}