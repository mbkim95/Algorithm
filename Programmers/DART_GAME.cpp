#include <iostream>

#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
	int prev = 0;
	int num = 0;
	int sum = 0;
	bool option = false;
	bool ten = false;
	for (int i = 0; i<dartResult.length(); i++) {
		if (ten) {
			ten = false;
			continue;
		}
		char tmp = dartResult[i];
		cout << "tmp : " << tmp << " sum : " << sum << " num : " << num << '\n';
		if ('0' <= tmp && tmp <= '9') {
			if (!option) {
				prev = num;
				sum += num;
			}
			num = tmp - '0';
			option = false;
			if (tmp == '1' && dartResult[i + 1] == '0') {
				ten = true;
				num = 10;
			}
		}
		else if (tmp == 'S') num = num;
		else if (tmp == 'D') num = pow(num, 2);
		else if (tmp == 'T') num = pow(num, 3);
		else if (tmp == '*') {
			num *= 2;
			sum += prev;
			prev = num;
			sum += num;
			option = true;
		}
		else if (tmp == '#') {
			num *= -1;
			prev = num;
			sum += num;
			option = true;
		}
	}
	if (!option) sum += num;
	return sum;
}

int main() {
	string str = "10T*10T*10T*";
	cout << solution(str) << '\n';
	return;
}