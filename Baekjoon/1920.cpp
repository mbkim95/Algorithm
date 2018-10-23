#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	scanf("%d", &m);
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", binary_search(v.begin(), v.end(), tmp));
	}
	return 0;
}