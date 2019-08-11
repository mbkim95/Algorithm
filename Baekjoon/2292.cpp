#include <iostream>
using namespace std;

int solve(int n) {
	int idx = 1;
	if (n == 1)
		idx = 1;
	else {
		while (true) {
			if (n - 1 > 3 * idx * idx + 3 * idx){
				idx++;
			}else if (n - 1 <= 3 * idx * idx + 3 * idx) {
				idx++;
				break;
			}
		}
	}
	return idx;
}

int main() {
	int n;
	cin >> n;
	cout << solve(n) << '\n';
	return 0;
}