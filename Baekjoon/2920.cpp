#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> melody(8);
	vector<int> temp;
	for (int i = 0; i < 8; i++)
		cin >> melody[i];

	temp = melody;
	sort(temp.begin(), temp.end());

	bool find = true;
	for (int i = 0; i < 8; i++) {
		if (melody[i] != temp[i]) {
			find = false;
			break;
		}
	}

	if (!find) {
		find = true;
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < 8; i++) {
			if (melody[i] != temp[i]) {
				find = false;
				break;
			}
		}

		if (find)
			cout << "descending" << '\n';
		else
			cout << "mixed" << '\n';
	}
	else {
		cout << "ascending" << '\n';
	}
	return 0;
}