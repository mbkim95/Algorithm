#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int r[4];
	cin >> r[0] >> r[1] >> r[2] >> r[3];
	sort(r, r + 4);
	cout << r[0] * r[2] << '\n';
	return 0;
}