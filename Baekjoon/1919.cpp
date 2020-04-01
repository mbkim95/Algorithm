#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int alpha[26] = { 0 }, cnt = 0;
	string s1, s2;
	cin >> s1 >> s2;
	for (char s : s1) alpha[s - 'a']++;
	for (char s : s2) alpha[s - 'a']--;
	for (int i = 0; i < 26; i++) if (alpha[i] != 0) cnt += abs(alpha[i]);
	cout << cnt << '\n';
	return 0;
}