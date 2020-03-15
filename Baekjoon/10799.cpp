#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0;
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else {
			s.pop();
			if (str[i - 1] == '(')
				ans += s.size();
			else
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}