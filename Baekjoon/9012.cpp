#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int c;
	cin >> c;
	stack<char> s;
	while (c--) {
		string vps;
		cin >> vps;
		int flag = 0;
		for (int i = 0; i < vps.size(); i++) {
			s.push(vps.at(i));
		}
		int a = 0, b = 0;
		for (int i = 0; i < vps.size(); i++) {
			char tmp = s.top();
			s.pop();
			if (tmp == '(')
				a++;
			else if (tmp == ')')
				b++;
			if (a > b) {
				cout << "NO" << '\n';
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			if (a != b)
				cout << "NO" << '\n';
			else
				cout << "YES" << '\n';
		}
	}
}