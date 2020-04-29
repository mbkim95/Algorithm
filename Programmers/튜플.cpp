#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<vector<int>> parse_string(string s) {
    vector<vector<int>> ret;
    int num = 0;
    vector<int> tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') continue;
        else if ('0' <= s[i] && s[i] <= '9') {
            num = 10 * num + (s[i] - '0');
        }
        else if (s[i] == ',') {
            if (num != 0) {
                tmp.push_back(num);
                num = 0;
            }
        }
        else if (s[i] == '}' && num != 0) {
            tmp.push_back(num);
            ret.push_back(tmp);
            num = 0;
            tmp.clear();
        }
    }
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    set<int> tmp_set;
    vector<vector<int>> tmp = parse_string(s);
    sort(tmp.begin(), tmp.end(), cmp);
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < tmp[i].size(); j++) {
            if (tmp_set.find(tmp[i][j]) == tmp_set.end()) {
                tmp_set.insert(tmp[i][j]);
                answer.push_back(tmp[i][j]);
            }
        }
    }
    return answer;
}