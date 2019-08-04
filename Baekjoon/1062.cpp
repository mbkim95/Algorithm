
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define A 'a' - 'a'
#define C 'c' - 'a'
#define I 'i' - 'a'
#define N 'n' - 'a'
#define T 't' - 'a'

int n, k, ans;
vector<string> words;
vector<bool> alpha;

void initialization() {
	alpha = vector<bool>(26, false);
	alpha[A] = true;
	alpha[C] = true;
	alpha[I] = true;
	alpha[N] = true;
	alpha[T] = true;
}

int getAnswer() {
	int ret = 0;
	for (int i = 0; i < words.size(); i++) {
		bool find = true;
		string str = words[i];
		for (int j = 4; j < str.length()-4; j++) {
			char ch = words[i][j];
			if (!alpha[ch - 'a']) {
				find = false;
				break;
			}
		}
		if (find)
			ret++;
	}
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt == k - 5) {
		ans = max(ans, getAnswer());
		return;
	}

	for (int i = idx + 1; i < 26; i++) {
		if (alpha[i])
			continue;
		alpha[i] = true;
		dfs(i, cnt + 1);
		alpha[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	initialization();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		words.push_back(str);
	}
	if (k < 5) {
		cout << 0 << '\n';
	}
	else {
		dfs(0, 0);
		cout << ans << '\n';
	}
	return 0;
}