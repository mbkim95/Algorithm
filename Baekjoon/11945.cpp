#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	while (n--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}