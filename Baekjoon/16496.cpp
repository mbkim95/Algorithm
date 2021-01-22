#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;

bool comp(const string& a, const string& b) {
	return a + b > b + a;
}

string solution(vector<int>& numbers) {
	string answer = "";
	bool is_all_zero = true; // 모든 숫자가 0인지 체크하기 위한 변수
	vector<string> nums;

	for (int num : numbers) {
		nums.push_back(to_string(num));
		if (num != 0) is_all_zero = false;
	}
	if (is_all_zero) return "0";

	sort(nums.begin(), nums.end(), comp);

	for (string num : nums) answer += num;
	return answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    numbers.resize(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    cout << solution(numbers) << '\n';
    return 0;
}
