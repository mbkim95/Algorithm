#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// LIS				O(nlogn)

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> s;
		s.push_back(-9999);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (s.back() < x)
				s.push_back(x);
			else {
				auto it = lower_bound(s.begin(), s.end(), x);
				*it = x;
			}
		}
		cout << s.size() - 1 << '\n';		
	}	
}