#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++) pq.push(scoville[i]);
    
    while(pq.size() > 1){ // 음식 1개가 될 때까지 섞기
        if(pq.top() >= k) break; // 가장 낮은 스코빌 지수가 K 이상인 경우
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        answer++;
    }
    if(pq.top() < k) return -1; // 음식이 1개이고 스코빌 지수가 K 미만인 경우
    return answer;
}