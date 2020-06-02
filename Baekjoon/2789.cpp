#include <iostream>
#include <set>
using namespace std;

char ch[] = { 'C','A','M','B','R','I','D','G','E' };

int main() {
	set<char> s;
	for (char c : ch) 
		s.insert(c);
	
	string str, ans = "";
	cin >> str;
	for (char c : str) {
		if (s.count(c) == 0) ans += c;
	}
	cout << ans << '\n';
	return 0;
}