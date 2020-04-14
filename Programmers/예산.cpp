#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int left = 0;
    //
	int right = *max_element(budgets.begin(), budgets.end());
	int sum = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		sum = 0;
		for (int v : budgets){
			if (v < mid) sum += v;
			else sum += mid;
		}
		if (sum > M) {
			right = mid - 1;
		}
		else {
			answer = max(answer, mid);
			left = mid + 1;
		}
	}
	return answer;
}