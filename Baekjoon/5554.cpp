#include <iostream>
using namespace std;

int main() {
	int time = 0;

	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		time += tmp;
	}

	cout << time / 60 << '\n' << time % 60 << '\n';
	return 0;
}