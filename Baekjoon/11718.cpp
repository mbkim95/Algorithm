#include <cstdio>

int main() {
	char str[101];
	while (scanf("%[^\n]\n", str) == 1)
		printf("%s\n", str);
}