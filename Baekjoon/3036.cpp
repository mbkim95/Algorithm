#include <iostream>
#include <vector>
using namespace std;

int n, root;
vector<int> wheels;

int getGCD(int num1, int num2) {
	if (num2 == 0) {
		return num1;
	}
	return getGCD(num2, num1 % num2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> root;
	wheels = vector<int>(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> wheels[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int gcd = getGCD(root, wheels[i]);
		cout << root / gcd << '/' << wheels[i] / gcd << '\n';
	}
	return 0;
}