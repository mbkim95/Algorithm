#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int solve() {
	string tmp = "";
	int ans = 0;
	bool minus = false;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) 
				ans -= stoi(tmp);
			else
				ans += stoi(tmp);
			tmp = "";
			if (str[i] == '-')
				minus = true;
		}
		else {
			tmp += str[i];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	cout << solve() << '\n';
	return 0;
}