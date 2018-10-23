#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int t;
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		double cnt = 0;
		double avg = 0;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			double tmp;
			cin >> tmp;
			avg += tmp;
			v.push_back(tmp);
		}
		avg /= n;
		for (int i = 0; i < n; i++) {
			if (avg < v[i])
				cnt++;
		}
		double ans = (cnt * 100) / n;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout <<  ans << '%' << '\n';
	}
}