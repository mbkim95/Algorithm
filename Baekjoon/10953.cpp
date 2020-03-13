#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n1, n2;
		scanf("%d%*c%d", &n1, &n2);
		printf("%d\n", n1 + n2);
	}
}