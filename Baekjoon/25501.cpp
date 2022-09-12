#include <iostream>
using namespace std;

int cnt;

int recursion(const string& s, int l, int r) {
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    return recursion(s, l+1, r-1);
}

int is_palindrome(const string& s) {
    return recursion(s, 0, s.length()-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cnt = 0;
        cout << is_palindrome(s) << ' ' << cnt << '\n';
    }

    return 0;
}