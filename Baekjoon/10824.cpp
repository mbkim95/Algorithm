#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int num1, num2;
    long long sum = 0;
	
	for (int i = 0; i < 2; i++) {
		cin >> num1 >> num2;
		s = to_string(num1) + to_string(num2);
		sum += stoll(s);
	}
	cout << sum << '\n';
	return 0;
}