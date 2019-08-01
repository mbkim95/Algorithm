#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int findStartIdx() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == -1) {
			ret = i;
			break;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	v = vector<int>(n, -1);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		int idx = findStartIdx();
		for (int j = 0; j < tmp; j++) {
			if (v[idx] == -1)
				idx++;		
			while (v[idx] != -1)
				idx++;			
		}
		v[idx] = i;
	}
	for (int a = 0; a < n; a++)
		cout << v[a] << ' ';
	cout << '\n';
	return 0;
}