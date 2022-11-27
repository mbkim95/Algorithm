#include <iostream>
using namespace std;

bool a[26];

int main() {
    int t;
    cin >> t;
    while(t--) {
        for(int i=0; i<=26; i++) a[i] = false;
        string s;
        cin >> s;
        for(char c : s) a[c-'A'] = true;
        int sum = 0;
        for(int i=0; i<26; i++) if(!a[i]) sum += 'A' + i;
        cout << sum << '\n';
    }
    return 0;
}