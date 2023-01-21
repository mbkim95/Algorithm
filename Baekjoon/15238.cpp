#include <iostream>
#include <map>
using namespace std;

int n, ans;
char r;
string s;
map<char, int> m;

int main() {
    cin >> n;
    cin >> s;
    for(char c : s) {
        m[c]++;
        if(ans < m[c]) {
            ans = m[c];
            r = c;
        }
    }
    cout << r << ' ' << ans << '\n';
    return 0;
}