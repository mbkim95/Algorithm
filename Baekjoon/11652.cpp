#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long ans;
vector<long long> v;

void solve() {
	sort(v.begin(), v.end());
	v.push_back(0);
	ans = v[0];
	int cnt = 1;
	int maxCnt = 1;
	for (int i = 1; i <= n; i++) {
		if (v[i] != v[i - 1]){
			if (maxCnt < cnt) {
				maxCnt = cnt;
				ans = v[i - 1];
			}
			cnt = 1;
		}
		else 
			cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	solve();
	cout << ans << '\n';
	return 0;
}