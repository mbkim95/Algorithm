#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    for(int i=2; i<=n; i++){
        int size = answer.size();
        answer.push_back(0);
        for(int j=size-1; j>=0; j--)
            answer.push_back(!answer[j]);
    }
    return answer;
}