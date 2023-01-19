#include <iostream>
#include <string>
using namespace std;

bool isAnswer(string& s) {
    for(int i=0; i<s.length() / 2; i++) if(s[i] != s[s.length()-1-i]) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, tmp, r = 0;
        cin >> n;
        tmp = n;

        while(tmp > 0) {
            r = 10 * r + tmp % 10;
            tmp /= 10;
        }
        string s = to_string(n + r);
        if(isAnswer(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}