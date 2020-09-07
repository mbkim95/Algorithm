#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char Hex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

string dec_to_n(int n, int number) {
	if (number == 0 || n == 10) return to_string(number);
	string ret = "";
	while (number > 0) {
		int div = number % n;
		if (div >= 10) ret = Hex[div - 10] + ret;
		else ret = to_string(div) + ret;
		number /= n;
	}
	return ret;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
    string num = "";
	for (int i = 0; i <= t * m; i++)
        num += dec_to_n(n, i);
		

	for (int i = 0; i < t; i++)
		answer += num[m * i + p - 1];
	return answer;
}