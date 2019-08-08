#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int mat[100][100];

int getSum(int x, int y, int dir) {
	int sum = 0;
	if (dir == 0) 
		for (int i = 0; i < 100; i++) 
			sum += mat[y][i];
	else
		for (int i = 0; i < 100; i++) 
			sum += mat[i][x];
	return sum;
}

int solve() {
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		ans = max(ans, getSum(0, i, 0));
		ans = max(ans, getSum(i, 0, 1));
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) 
		sum += mat[i][i];
	ans = max(ans, sum);
	sum = 0;
	for (int i = 0; i < 100; i++) 
		sum += mat[i][99 - i];
	ans = max(ans, sum);
	return ans;
}

int main() {
	for (int c = 1; c <= 10; c++) {
		int t;
		scanf("%d", &t);
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &mat[i][j]);
		printf("#%d %d\n", c, solve());
	}
	return 0;
}