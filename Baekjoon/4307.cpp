#include <iostream>
#include <algorithm>
using namespace std;

int ant[1000000];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int len, n;
		cin >> len >> n;
		for (int i = 0; i < n; i++)
			cin >> ant[i];
		int half = len / 2;
		int Max = 0, Min = 0;
		for (int i = 0; i < n; i++) {
			if (ant[i] < half) {
				Min = max(Min, ant[i]);
				Max = max(Max, len - ant[i]);
			}
			else {
				Min = max(Min, len - ant[i]);
				Max = max(Max, ant[i]);
			}
		}
		cout << Min << ' ' << Max << '\n';
	}
}