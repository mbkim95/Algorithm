#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int korean = a % c == 0 ? a / c : a / c + 1;
	int math = b % d == 0 ? b / d : b / d + 1;
	cout << l - max(korean, math) << '\n';
	return 0;
}