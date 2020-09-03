#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i : works) pq.push(i);
    while (n--) {
        int tmp = pq.top();
        if (tmp > 0) {
            pq.pop();
            pq.push(tmp - 1);
        }
    }
    while (!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        answer += (tmp * tmp);
    }
    return answer;
}