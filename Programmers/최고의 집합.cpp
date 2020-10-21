#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n) return {-1};
    int rest = s % n;
    for(int i=0; i<n; i++) answer.push_back((s - rest) / n);    
    for(int i=0; i<rest ;i++) answer[i]++;        
    sort(answer.begin(), answer.end());
    return answer;
}