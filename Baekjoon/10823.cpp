#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string str;
	string tmp;
	while (cin >> tmp)
		str += tmp;

	istringstream sin(str);

	string num;
	int sum = 0;

	while (getline(sin, num, ','))
		sum += stoi(num);
	
	cout << sum << '\n';
	return 0;
}