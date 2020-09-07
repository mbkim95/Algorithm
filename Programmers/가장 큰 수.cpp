#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	bool is_all_zero = true; // 모든 숫자가 0인지 체크하기 위한 변수
	vector<string> nums; // 문자열로 변환한 숫자를 담을 벡터

	// 모든 숫자를 문자열로 변경
	for (int num : numbers) {
		nums.push_back(to_string(num));
		if (num != 0) is_all_zero = false;
	}
	if (is_all_zero) return "0"; // 모든 숫자가 0이면 정답도 0이 된다

	sort(nums.begin(), nums.end(), comp);

	for (string num : nums) answer += num;
	return answer;
}