#include <iostream>
#include <algorithm>
using namespace std;

int N, L, c[1001];

double solve(int num) {
	double ret = std::numeric_limits<double>::max(), tmp = 0.0;
	for (int i = 0; i <= N - num; i++) {
		for (int j = i; j < i+num; j++) 
			tmp += c[j];			
		tmp /= num;
		ret = min(ret, tmp);
		tmp = 0.0;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++)
			scanf("%d", &c[i]);
		double ans = std::numeric_limits<double>::max();
		for (int i = L; i<= N; i++)
			ans = min(ans, solve(i));
		printf("%.12f\n", ans);
	}
	return 0;
}