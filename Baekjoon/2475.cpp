#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int ans = 0;
	for(int i=0; i<5; i++){
		int n;
		cin >> n;
		int rest = n % 10;
		ans += pow(rest, 2);
	}
	cout << ans % 10 << '\n';
	return 0;
}