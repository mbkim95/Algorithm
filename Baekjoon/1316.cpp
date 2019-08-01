#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, ans;
vector<bool> chk;
string str;

int checkWord() {
	chk = vector<bool>(26, false);
	char tmp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (tmp != str[i]) {
			if (chk[str[i] - 'a'])
				return 0;
			else {
				chk[str[i] - 'a'] = true;
			}
		}
		tmp = str[i];
	}
	return 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		ans += checkWord();
	}
	cout << ans << '\n';
	return 0;
}