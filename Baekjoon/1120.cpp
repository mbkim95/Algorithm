#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int ans = INT_MAX;

	int diff = str2.length() - str1.length();
	for (int i = 0; i <= diff; i++) {
		int tmp = 0;
		for (int j = 0; j < str1.length(); j++) {
			if (str1[j] != str2[i + j])
				tmp++;
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}