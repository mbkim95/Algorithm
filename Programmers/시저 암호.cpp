#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(c == ' ') continue;
        else if('a' <= c && c <= 'z'){
            if(c + n > 'z') s[i] = 'a' + (c + n - 'z' - 1);
            else s[i] += n;
        }
        else if('A' <= c && c <= 'Z'){
            if(c + n > 'Z') s[i] = 'A' + (c + n - 'Z' - 1);
            else s[i] += n;
        }
    }
    return s;
}