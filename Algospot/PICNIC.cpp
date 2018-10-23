#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool r[10][10], chk[10];

int countPairs() {
	int findIdx = -1;

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			findIdx = i;
			break;
		}
	}

	if (findIdx == -1)
		return 1;

	int ret = 0;
	
	for (int i = findIdx + 1; i < n; i++) {
		if (r[findIdx][i] && !chk[i]) {
			chk[findIdx] = chk[i] = true;
			ret += countPairs();
			chk[findIdx] = chk[i] = false;
		}
	}

	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(r, false, sizeof(r));
		memset(chk, false, sizeof(chk));
		for (int i = 0; i < m; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			r[tmp1][tmp2] = r[tmp2][tmp1] = true;
		}
		cout << countPairs() << '\n';
	}
	return 0;
}