#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1001], dp[1001];

int main() {
	cin >> n;

	arr[0] = 0;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[n] << endl;

}