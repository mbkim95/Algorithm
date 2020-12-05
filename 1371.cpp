#include <iostream>
#include <algorithm>
using namespace std;

int alphabet[26];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				alphabet[s[i] - 'a']++;
		s.clear();
	}

	int cnt = alphabet[0];

	for (int i = 1; i < 26; i++)
		cnt = max(alphabet[i], cnt);

	for (int i = 0; i < 26; i++)
		if (alphabet[i] == cnt)
			cout << (char)(i + 'a');
	cout << '\n';
	return 0;
}