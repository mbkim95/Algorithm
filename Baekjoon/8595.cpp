#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	string num = "";
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if ('0' <= s[i] && s[i] <= '9') num += s[i];
		else {
			if(num.length() != 0) ans += stoll(num);
			num = "";
		}
	}
	if (num.length() != 0) ans += stoll(num);
	cout << ans << '\n';
	return 0;
}