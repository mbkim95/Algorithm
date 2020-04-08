#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
    set<int> s;
    for(int i : nums)
        s.insert(i);
    if(s.size() > nums.size() / 2) answer = nums.size() / 2;
    else answer = s.size();
	return answer;
}