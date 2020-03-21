#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);
    bool find = false;
    while(pq.size() > 1){
        if(pq.top() >= k){
            bool find = true;
            break;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + 2 * b;
        pq.push(c);
        answer++;
    }
    
    if(!pq.empty() && pq.top() > k)
        find = true;
    if(!find) {
        answer = -1;
    }
    return answer;
}