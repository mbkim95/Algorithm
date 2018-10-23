#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	cin >> n;
	stack<int> s;
	while (n--) {
		string str;
		cin >> str;

		if (str == "push") {
			int tmp;
			cin >> tmp;
			s.push(tmp);
		}
		else if (str == "pop") {
			if (s.empty()) {				
				cout << -1 << '\n';
			}else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			cout << s.empty() << '\n';
		}
		else if (str == "top") {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}
}