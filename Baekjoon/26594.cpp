#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 987654321;
    int cnt = 0;
    char prev = s[0];
    for(char c : s) {
        if(c == prev) cnt++;
        else {
            ans = min(ans, cnt);
            cnt = 1;
        }
        prev = c;
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
    return 0;
}