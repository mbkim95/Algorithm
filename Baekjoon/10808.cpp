#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < 26; i++) 
		cout << count(s.begin(), s.end(), 'a'+i) << ' ';
	cout << '\n';

	return 0;
}