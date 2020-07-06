#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


vector<int> solution(vector<string> gems) {
    // 처음에 최대 구간으로 설정
    vector<int> answer = { 1, (int)gems.size() };
    // 보석을 담는 set
    set<string> jewels;
    // 보석의 개수를 세는 map
    map<string, int> ans;
    // 모든 종류의 보석을 중복을 없이 저장
    for (string j : gems) jewels.insert(j);

    int s = 0, e = 0;
    int diff = gems.size();

    while (true) {
        // 모든 보석이 다 담긴 경우
        if (ans.size() == jewels.size()) {
            if (diff > e - s) {
                diff = e - s;
                answer[0] = s + 1;
                answer[1] = e;
            }
            // 보석이 하나면 제거하고 시작 인덱스 증가
            if (ans[gems[s]] == 1) {
                ans.erase(gems[s]);
                s++;
            }
            // 같은 종류의 보석이 여러개면 1개 감소시키고 시작 인덱스 증가
            else if (ans[gems[s]] - 1 > 0) {
                ans[gems[s]]--;
                s++;                        
            }
        }
        // 끝까지 탐색하면 종료
        else if (e == gems.size()) break;
        // 보석 종류를 다 포함하지 못하면 끝 인덱스 증가
        else {
            ans[gems[e]]++;
            e++;
        }
    }    
    return answer;
}