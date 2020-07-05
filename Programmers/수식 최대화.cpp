#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<long long> numbers;
vector<int> ops;

void parse_expression(string expression) {
	int start = 0;
	for (int i = 0; i < expression.length(); i++) {
		char c = expression[i];
		if (c == '*' || c == '+' || c == '-' || i == expression.length() - 1) {
			if (i == expression.length() - 1) numbers.push_back(stoi(expression.substr(start, i - start + 1)));
			else numbers.push_back(stoi(expression.substr(start, i - start)));
			if (c == '*') ops.push_back(0);
			else if (c == '+') ops.push_back(1);
			else if( c == '-') ops.push_back(2);
			start = i + 1;
		}
	}
}

long long solution(string expression) {
	parse_expression(expression);
	long long answer = 0;
	vector<int> operation = { 0, 1, 2 };

	vector<long long> tmp_num;
	vector<int> tmp_op;
	do {
		tmp_num = numbers;
		tmp_op = ops;
		vector<bool> chk(tmp_num.size(), false);
		for (int i : operation) {
			for (int j = 0; j < tmp_op.size(); j++) {
				if (i == tmp_op[j]) {
					int idx = j;
					for (idx = j; idx >= 0; idx--)
						if (!chk[idx]) break;

					int l;
					for (l = j + 1; l < tmp_num.size(); l++)
						if (!chk[l]) break;

					if (i == 0)  tmp_num[idx] *= tmp_num[l];
					else if (i == 1) tmp_num[idx] += tmp_num[l];
					else tmp_num[idx] -= tmp_num[l];
					chk[l] = true;
				}
			}
		}
		answer = max(answer, abs(tmp_num[0]));
	} while (next_permutation(operation.begin(), operation.end()));
	return answer;
}