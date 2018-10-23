#include <cstdio>
#include <algorithm>
using namespace std;

int arr[5000001];

int main() {
	
	int n, k;
	
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	sort(arr + 1, arr + n+1);

	printf("%d\n", arr[k]);
}