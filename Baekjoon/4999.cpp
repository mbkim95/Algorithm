#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << (str1.length() >= str2.length() ? "go" : "no") << '\n';
	return 0;
}