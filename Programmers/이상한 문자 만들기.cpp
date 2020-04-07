#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool find = true;
    int idx = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            find = true;
            idx = -1;
        }else if(idx % 2 == 0 && 'a' <= s[i] && s[i] <= 'z'){
            s[i] -= ('a' - 'A');
            find = false;
        }else if(idx % 2 == 1 && 'A' <= s[i] && s[i] <= 'Z'){
            s[i] += ('a' - 'A');
            find = false;
        }
        idx++;
    }
    return s;
}