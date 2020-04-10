#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int time = 0;
    // 작업 시작 시간 순으로 정렬
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && time >= jobs[idx][0]) {
            pq.push(jobs[idx]);
            idx++;
            continue;
        }
        // 큐가 비어있지 않으면 종료 시간이 가장 짧은 작업 처리
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += (time - pq.top()[0]);
            pq.pop();
        }
        // 큐가 비어있는 경우 다음 작업으로 시간 이동
        else
            time = jobs[idx][0];
    }
    return answer / jobs.size();
}