#include <iostream>
using namespace std;

bool num[10001];

int chk(int num) {
	int ret = num;

	while (num > 0) {
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		int idx = chk(i);
		if (idx < 10001) {
			num[idx] = true;
		} 
	}

	for (int i = 1; i <= 10000; i++) {
		if (num[i] == false)
			cout << i << endl;
	}
	return 0;
}