#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getSize(int num) {
	int ret = 0;

	while (num > 0) {
		num /= 10;
		ret++;
	}
	return ret;
}

int getCountValue(long long len) {
	int ret = 9;;
	if (len == 1)
		return ret;
	else {
		while (len > 1) {
			ret *= 10;
			len--;
		}
	}
	return ret;
}

int main() {
	long long num;
	cin >> num;
	int len = getSize(num);
	long long ans = 0;
	if (len == 1) {
		ans = num;
	}
	else {
		for (int i = len - 1; i >= 1; i--) {
			ans += (i * getCountValue(i));
		}
		ans += (num + 1 - pow(10, len-1)) * len;
	}
	cout << ans << '\n';
	return 0;
}