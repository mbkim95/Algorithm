#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int cache[301][301];

int dp(int a, int b) {
	int& ret = cache[a][b];

	if (ret != -1)
		return ret;

	if (a == 1 || b == 1) {
		return ret = a * b - 1;
	}
	return ret = (a - 1) + a * dp(1, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	cout << dp(n, m) << '\n';
	return 0;
}