#include <cstdio>
using namespace std;

int b[64][64];
int n;

bool check(int x, int y, int size) {
	int tmp = b[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tmp != b[i][j])
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int size) {
	if (check(x, y, size)) {
		printf("%d", b[y][x]);
		return;
	}
	else {
		int s = size / 2;
		printf("(");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + s * j, y + s * i, s);	
			}
		}
		printf(")");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &b[i][j]);	
	solve(0, 0, n);
}