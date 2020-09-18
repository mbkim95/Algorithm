#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	float t;
	cin >> t;
	float h = t / 2;
	cout << (int)(h * h + 0.5) << '\n';
	return 0;
}