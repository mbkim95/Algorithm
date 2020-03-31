#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    set<string> s;
    vector<int> dp(t.length()+1, INT_MAX);
    
    // set에 단어 조각 삽입
    for(int i=0; i<strs.size(); i++)
        s.insert(strs[i]);
    
    dp[t.length()] = 0;
    
    // t의 뒤부터 탐색
    for(int i=t.length()-1; i>=0; i--){
        string tmp = "";
        // i, j 값을 이용해서 단어 조각 생성
        for(int j=i; j<t.length(); j++){
            tmp += t[j];
            if(i + 5 < j) break;            
            // set에 있는 단어조각인지 검사
            if(s.find(tmp) != s.end()){
                if(dp[j+1] != INT_MAX){
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
    }
    answer = dp[0] != INT_MAX ? dp[0] : -1;
    return answer;
}