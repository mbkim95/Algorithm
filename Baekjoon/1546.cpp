#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<float> bef, aft;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		float tmp;
		scanf("%f", &tmp);
		bef.push_back(tmp);
	}
	float M = bef[0];
	for (int i = 0; i < n; i++) 
		M = max(M, bef[i]);	
	for (int i = 0; i < n; i++)
		aft.push_back(bef[i] / M * 100);
	float avg = 0;
	for (int i = 0; i < n; i++)
		avg += aft[i];
	printf("%.2f\n", avg / n);
}