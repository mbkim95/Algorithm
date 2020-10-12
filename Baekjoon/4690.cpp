#include <iostream>
using namespace std;

int main() {
	for (int n = 3; n <= 100; n++) {
		int a = n * n * n;
		for (int i = 2; i <= 100; i++) {
			int b = i * i * i;
			if (a <= b) break;
			for (int j = i + 1; j <= 100; j++) {
				int c = j * j * j;
				if (a <= b + c) break;
				for (int k = j + 1; k <= 100; k++) {
					int d = k * k * k;
					if (a == b + c + d) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", n, i, j, k);
						break;
					}
				}
			}
		}
	}
	return 0;
}