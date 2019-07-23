#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char symbol[9];
bool used[10];
int tmp[10];
string ans1, ans2;
long long int tmp_ans1, tmp_ans2;

void dfs(int idx, int num) {
	tmp[idx] = num;

	if (idx == k) {
		long long t = 0;
		for (int i = 0; i <= k; i++)
			t = t * 10 + tmp[i];
		if (tmp_ans1 < t) {
			tmp_ans1 = t;
			ans1.clear();
			for (int i = 0; i <= k; i++) {
				char ch = '0' + tmp[i];
				ans1 += ch;
			}
		}
		if (tmp_ans2 > t) {
			tmp_ans2 = t;
			ans2.clear();
			for (int i = 0; i <= k; i++) {
				char ch = '0' + tmp[i];
				ans2 += ch;
			}
		}
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (!used[i]) {
			char sym = symbol[idx];
			if (sym == '<' && num < i) {
				used[i] = true;
				dfs(idx + 1, i);
				used[i] = false;
			}
			else if (sym == '>' && num > i) {
				used[i] = true;
				dfs(idx + 1, i);
				used[i] = false;
			}
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> symbol[i];
	tmp_ans1 = 0;
	tmp_ans2 = 9999999999;
	for (int i = 9; i >= 0; i--) {
		used[i] = true;
		dfs(0, i);
		used[i] = false;
	}
	cout << ans1 << '\n' << ans2 << '\n';
}