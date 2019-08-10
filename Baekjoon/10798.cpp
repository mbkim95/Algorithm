#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[5][16];

int main() {

	int len = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%s", &str[i]);
		len = max(len, (int)strlen(str[i]));
	}
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i] != ' ' && str[j][i] != '\0')
				printf("%c", str[j][i]);
		}
	}
	printf("\n");
	return 0;
}