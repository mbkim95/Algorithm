#include <iostream>
using namespace std;

int solve(int num) {
	if (num < 100)
		return num;
	else {
		int ret = 99;
		for (int i = 100; i <= num; i++) {
			int a = i/100, b = (i/10)%10, c = i%10;

			if (a + c == 2 * b) 
				ret++;
		}		
		return ret;
	}
}

int main() {
	int num;
	cin >> num;
	cout << solve(num) << '\n';
	return 0;
}