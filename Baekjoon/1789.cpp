#include <iostream>
using namespace std;

int main() {
	long long num;
	cin >> num;
	long long idx = 1;
	while (true) {
		long long sum = idx * (idx + 1) / 2;
		if (sum > num) break;
		idx++;
	}
	cout << --idx << '\n';;
}