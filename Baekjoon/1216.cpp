#include <iostream>
#include <algorithm>
using namespace std;

string name;
int alpha[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> name;

	for (char c : name)
		alpha[c - 'A']++;

	int odd_cnt = 0;
	bool is_possible = true;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) odd_cnt++;
		if (odd_cnt > 1) {
			is_possible = false;
			break;
		}
	}
	if(!is_possible) cout << "I'm Sorry Hansoo\n";
	else {
		string ans = "";
		char odd = 'a';
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alpha[i] / 2; j++)
				ans += (char)(i + 'A');
			if (alpha[i] % 2 == 1) odd = i + 'A';
		}
		string rev = ans;
		reverse(rev.begin(), rev.end());
		if (odd == 'a') cout << ans + rev << '\n';
		else cout << ans + odd + rev << '\n';
	}
	return 0;
}