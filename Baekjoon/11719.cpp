#include <cstdio>

int main() {
	char str;	
	while ((str = getchar()) && str != EOF)
		printf("%c", str);
}