#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
		for (int j = 0; j <= n-i; j++)
			printf(" ");
	}
}