#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int idx = 0;
	cin >> x >> y;

	for (int i = 0; i<x; i++) {
		if ((i + 1) == x)
			idx += y;
		else
			idx += month[i];
	}	
	
	cout << days[idx % 7] << '\n';

	return 0;
}