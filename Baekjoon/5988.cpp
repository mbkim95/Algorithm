#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		if ((tmp[tmp.length() - 1] - '0') % 2) cout << "odd\n";
		else cout << "even\n";
	}	
	return 0;
}