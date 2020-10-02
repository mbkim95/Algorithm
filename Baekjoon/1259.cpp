#include <iostream>
using namespace std;

int main() {
	while (true) {
		string tmp;
		cin >> tmp;
		if (tmp == "0") break;
		int len = tmp.length();
		int left = 0;
		int right = len - 1;
		bool is_palindrome = true;
		while (left <= right) {
			if (tmp[left] != tmp[right]) {
				cout << "no\n";
				is_palindrome = false;
				break;
			}
			left++;
			right--;
		}
		if (is_palindrome)
			cout << "yes\n";
	}
	return 0;
}