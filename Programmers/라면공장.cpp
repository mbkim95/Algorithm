#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int day = 0;
	int idx = 0;
	priority_queue<int> pq;
	while (day < k) {
		// 공급받을 수 있는 날이 되면 pq에 저장
		if (idx < dates.size() && day == dates[idx]) {
			pq.push(supplies[idx]);
			idx++;
		}
		// 남은 밀가루가 없으면 가장 많은 양 공급받음
		if (stock == 0) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		stock--;
		day++;
	}
	return answer;
}