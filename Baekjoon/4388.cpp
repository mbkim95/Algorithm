#include <iostream>
using namespace std;

int n1, n2;
int num1[10], num2[10];

int getLength(int n, int num[]) {
	int ret = 0;
	while (n > 0) {
		num[ret++] = (n % 10);
		n /= 10;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> n1 >> n2;
		if (n1 == 0 && n2 == 0)
			break;
		int l1 = getLength(n1, num1);
		int l2 = getLength(n2, num2);
		int length = l1 > l2 ? l1 : l2;
		int cnt = 0;
		int carry = 0;
		for (int i = 0; i < length; i++) {
			int sum = num1[i] + num2[i] + carry;
			if (sum > 9) {
				carry = 1;
				cnt++;
			}
			else carry = 0;
		}
		cout << cnt << '\n';
	}
	return 0;
}
