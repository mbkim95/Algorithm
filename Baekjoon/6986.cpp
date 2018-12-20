#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<double> v1, v2;
	for (int i = 0; i < n; i++) {
		double tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	v2 = v1;
	for (int i = 0; i < k; i++) {
		v1.erase(v1.begin());
		v1.erase(v1.end() - 1);
		v2[i] = v2[k];
		v2[n - 1 - i] = v2[n - 1 - k];
	}

	double avg1 = 0, avg2 = 0;

	for (int i = 0; i < v1.size(); i++)
		avg1 += v1[i];

	for (int i = 0; i<v2.size(); i++)
		avg2 += v2[i];

	avg1 /= v1.size();
	avg2 /= v2.size();
	printf("%.2lf\n", avg1 + 0.00000001);
	printf("%.2lf\n", avg2 + 0.00000001);
	return 0;
}