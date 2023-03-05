#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, ans = "";
        cin >> s;
        char tmp = ' ';
        for(char c : s) {
            if(c == tmp) continue;
            tmp = c;
            ans += c;
        }
        cout << ans << '\n';
    }
    return 0;
}