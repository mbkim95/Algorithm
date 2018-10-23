#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int cnt = 0;

	while (cin >> str)
		cnt++;

	cout << cnt << '\n';

	return 0;
}