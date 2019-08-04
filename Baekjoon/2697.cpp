#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char num[81];
		scanf("%s", num);
		if (next_permutation(num, num + strlen(num)))
			printf("%s\n", num);
		else
			printf("BIGGEST\n");
	}
	return 0;	
}