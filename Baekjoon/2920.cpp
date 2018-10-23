#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(8);

	for (int i = 0; i < 8; i++)
		cin >> v[i];

	int first = v[0];
	int flag = 0;

	for (int i = 1; i < 8; i++) {
		if (first == 1 && v[i] != first + i) {
			cout << "mixed" << '\n';
			flag = 1;
			break;
		}
		else if (first == 8 && v[i] != first - i) {
			cout << "mixed" << '\n';
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		if (first == 1)
			cout << "ascending" << '\n';
		else
			cout << "descending" << '\n';
	}
	return 0;
}