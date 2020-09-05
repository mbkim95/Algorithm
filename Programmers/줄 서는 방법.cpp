#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long factorial[21];

void pre_calc() {
	factorial[0] = 1;
	for (int i = 1; i <= 20; i++)
		factorial[i] = factorial[i - 1] * i;
}

vector<int> solution(int n, long long k) {
	pre_calc();
	vector<bool> chk(n, false);
	vector<int> answer;
	int select = 0;
	while (answer.size() != n) {
		for (int i = 0; i < n; i++) {
			if (chk[i]) continue;
			long long num = factorial[n - 1 - select];
			if (k > num) {
				k -= num;
				continue;
			}
			select++;
			answer.push_back(i + 1);
			chk[i] = true;
			break;

		}
	}
	return answer;
}