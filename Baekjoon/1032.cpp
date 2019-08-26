#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++)
		cin >> str[i];
	string ans = str[0];
	for (int i = 1; i < n; i++) 
		for (int j = 0; j < ans.length(); j++) 
			if (ans[j] != str[i][j]) {
				ans[j] = '?';
	cout << ans << '\n';
	return 0;
}