#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if ('a' <= c && c <= (char)('z' - 13) || 'A' <= c && c <= (char)('Z' - 13)) str[i] += 13;
		if ((char)('a' + 13) <= c && c <= 'z' || (char)('A' + 13) <= c && c <= 'Z') str[i] -= 13;
	}
	cout << str << '\n';
	return 0;
}