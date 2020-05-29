#include <iostream>
using namespace std;

int n;
int table[100][2];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			cin >> table[i][j];
		
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (table[i][1] % table[i][0]);
	cout << ans << '\n';
	return 0;
}