#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, len;
vector<int> num;

int main() {
	scanf("%d", &n);
	num = vector<int>(10001);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[tmp]++;
	}
	
	for (int i = 1; i <=10000; i++) {
		for (int j = 0; j < num[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}