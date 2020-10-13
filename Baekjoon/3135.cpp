#include <iostream>
#include <cmath>
using namespace std;

int n, a, b;
int favorite[5];

int main() {
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> favorite[i];
	int answer = 0;
	int f_idx = 0;
	int min_diff = 987654321;
	for (int i = 0; i < n; i++) {
		int diff = abs(b - favorite[i]);
		if (min_diff > diff) {
			min_diff = diff;
			f_idx = i;
		}
	}
	cout << (abs(a - b) < 1 + abs(favorite[f_idx] - b) ? abs(a - b) : 1 + abs(favorite[f_idx] - b)) << '\n';
	return 0;
}