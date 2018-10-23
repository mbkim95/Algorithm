#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {
		int A = 0, a = 0, s = 0, n = 0;
		for (int i = 0; i < str.size(); i++) {
			char tmp = str.at(i);
			if ('A' <= tmp && tmp <= 'Z')
				A++;
			else if ('a' <= tmp && tmp <= 'z')
				a++;
			else if (tmp == ' ')
				s++;
			else
				n++;
		}
		cout << a << ' ' << A << ' ' << n << ' ' << s << '\n';
	}
	return 0;	
}