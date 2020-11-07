#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, ans;
vector<int> cand;
int num[101];
bool chk[101];
set<int> s;

void dfs(int idx, int cnt, int start) {
	if (cnt > 1 && idx == start) {		
		for (int i : cand) s.insert(i);
		return;
	}
	if (!chk[num[idx]]) {
		cand.push_back(num[idx]);
		chk[num[idx]] = true;
		dfs(num[idx], cnt + 1, start);
		chk[num[idx]] = false;
		cand.pop_back();
	}
}

int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);*/
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];		

	for (int i = 1; i <= n; i++) {
		dfs(i, 0, i);
	}

	for(int i=1; i<=n; i++)
		if (i == num[i]) {
			ans++;
			s.insert(i);
		}
	vector<int> answer;
	for (int i : s)
		answer.push_back(i);
	sort(answer.begin(), answer.end());

	cout << s.size() << '\n';
	for (int i : answer)
		cout << i << '\n';
}