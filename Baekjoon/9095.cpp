#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v(12);

int main() {
	int c;
	cin >> c;
	v[0] = 1;
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i <= 11; i++) 
		v[i] = v[i - 3] + v[i - 2] + v[i - 1];
	while (c--) {
		int n;
		cin >> n;
		cout << v[n] << '\n';
	}
}