#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int tmp[51] = { 0, };
	for (int c = 1; c <= t; c++) {
		int ans = 0;
		int size;
		int side = 0;
		scanf("%d", &size);
		for(int i=0; i<size; i++){
			for (int j = 0; j < size; j++) 
				scanf("%1d", &tmp[j]);
			int base = (size - 1) / 2;
			ans += tmp[base];
			for (int l = 1; l <= side; l++) ans += (tmp[base - l] + tmp[base + l]);
			if (i < (size - 1) / 2) side++;
			else side--;
		}
		printf("#%d %d\n", c, ans);
	}
	return 0;
}