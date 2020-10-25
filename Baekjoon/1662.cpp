#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	string str;
	stack<pair<int, int>> s;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == '(') s.push({ -1, i });
		else if (c == ')') {
			int cnt = 0;
			while (s.top().first != -1) {
				cnt += s.top().first;
				s.pop();
			}
			s.pop();
			int num = str[s.top().second] - '0';
			s.pop();
			s.push({ cnt * num, i });
		}
		else s.push({ 1, i });
	}
	int ans = 0;
	while (!s.empty()){
		ans += s.top().first;
		s.pop();
	}
	cout << ans << '\n';
	return 0;
}