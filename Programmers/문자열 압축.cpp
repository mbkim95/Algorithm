#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    int len = s.length();
    if (len < 3) return len;

    for (int t = 1; t <= len / 2; t++) {
        string tok = s.substr(0, t);
        string cmp;
        int cnt = 1;
        int ans = 0;
        bool find = false;
        for (int i = t; i < len; i += t) {
            cmp = s.substr(i, t);
            if (tok == cmp) {
                cnt++;
                find = true;
            } else {
                tok = cmp;
                if (cnt == 1) ans += t;
                else ans += t + to_string(cnt).size();
                cnt = 1;
                find = false;
            }
        }
        if (find) ans += t + to_string(cnt).size();
        else ans += cmp.size();
        answer = min(answer, ans);
    }
    return answer;
}