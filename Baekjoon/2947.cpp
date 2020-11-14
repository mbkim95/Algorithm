#include <iostream>
using namespace std;

int num[5];

bool is_sorted() {
	for (int i = 0; i < 5; i++)
		if (num[i] != i + 1) return false;
	return true;
}

int main() {
	for (int i = 0; i < 5; i++)
		cin >> num[i];

	while (!is_sorted()) {
		for (int i = 0; i < 4; i++) {
			if (num[i] > num[i + 1]) {
				int tmp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = tmp;
				for (int j = 0; j < 5; j++)
					cout << num[j] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}