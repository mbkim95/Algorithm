#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c, total = 0;
		double g, score = 0;		
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> c >> g;
			total += c;
			score += (c * g);
		}		
		cout << total << ' ';
		cout << fixed;
		cout.precision(1);
		cout << score / total << '\n';
	}	
	return 0;
}