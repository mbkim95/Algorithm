#include <iostream>
#define DIV 45678
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 5;
	for (int i = 2; i <= n; i++)
		ans = (ans + (i * 3 + 1)) % DIV;
	cout << ans << '\n';
	return 0;
}