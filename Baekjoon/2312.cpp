#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		int div = 2;
		int cnt = 0;
		bool flag = true;
		while (num != 1) {
			flag = true;
			if (num % div == 0) {
				cnt++;
				num /= div;
			}
			else {
				flag = false;
				if(cnt != 0)
					cout << div << ' ' << cnt << '\n';
				div++;
				cnt = 0;
			}
		}
		if (flag)
			cout << div << ' ' << cnt << '\n';
	}
	return 0;
}