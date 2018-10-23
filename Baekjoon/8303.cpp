#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int sum = 1;

	for (int i = 2; i <= n; i++) {
		sum += i;
	}
	printf("%d\n", sum);
}