#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	bitset<100000> a(A), b(B);
	cout << (a & b) << '\n';
	cout << (a | b) << '\n';
	cout << (a ^ b) << '\n';
	cout << (~a) << '\n';
	cout << (~b) << '\n';

	return 0;
}