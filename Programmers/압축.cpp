#include <string>
#include <vector>
#include <map>
using namespace std;

void setting(map<string, int>& m) {
    for (int i = 0; i < 26; i++) {
        string tmp = "";
        tmp += (char)('A' + i);
        m[tmp] = i + 1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    setting(m);    
    int idx = 0;
    int mapping = 27;
    while(idx < msg.length()){
        string tok;
        for (int i = msg.length(); i > idx; i--) {
            tok = msg.substr(idx, i - idx);
            if (m.find(tok) != m.end()) break;
        }
        answer.push_back(m[tok]);
        idx += tok.size();
        if (idx < msg.length()) {
            tok += msg[idx];
            m[tok] = mapping++;
        }
    }
    return answer;
}