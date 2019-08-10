#include <iostream>
#include <vector>
using namespace std;

int m;
vector<bool> cup;

void swap(int from, int to) {
	bool tmp = cup[from];
	cup[from] = cup[to];
	cup[to] = tmp;
}

int main() {
	cup = vector<bool>(4, false);
	cup[1] = true;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		swap(tmp1, tmp2);
	}

	for (int i = 1; i <= 3; i++)
		if (cup[i])
			cout << i << '\n';
	return 0;
}