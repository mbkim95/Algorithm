#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	vector<function<int(int, int)>> v;
	int a, b;
	cin >> a >> b;
	v.push_back([](int a, int b) {
		return a + b;
	});
	v.push_back([](int a, int b) {
		return a - b;
	});
	v.push_back([](int a, int b) {
		return a * b;
	});
	v.push_back([](int a, int b) {
		return a / b;
	});
	v.push_back([](int a, int b) {
		return a % b;
	});
	for (auto &f : v)
		cout << f(a, b) << '\n';
}