#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	while (true) {
		string str;
		getline(cin, str);
		stack<char> s;
		bool balance = true;
		if (str == ".")
			break;
		for (int i = 0; i < str.length(); i++) {
			char cur = str[i];
			if (cur == '(')
				s.push('(');
			else if (cur == '[')
				s.push('[');
			else if (cur == ')') {
				if (s.empty() || s.top() != '(') {
					balance = false;
					break;
				}
				s.pop();
			}
			else if (cur == ']') {
				if (s.empty() || s.top() != '[') {
					balance = false;
					break;
				}
				s.pop();
			}
		}
		if (!balance)
			cout << "no\n";
		else {
			if (!s.empty())
				cout << "no\n";
			else
				cout << "yes\n";
		}
	}
}