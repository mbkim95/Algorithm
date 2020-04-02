#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int n = progresses.size();
    for(int i=0; i<n; i++) q.push(i);
    
    while(!q.empty()){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(progresses[i] >= 100) continue;
            progresses[i] += speeds[i];
        }
        while(!q.empty() && progresses[q.front()] >= 100){
            q.pop();
            cnt++;
        }
        if(cnt != 0) answer.push_back(cnt);
    }
    return answer;
}