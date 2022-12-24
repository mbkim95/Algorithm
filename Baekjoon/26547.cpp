#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        for(int i=0; i<s.length(); i++) {
            if(i == 0) cout << s << '\n';
            else if(i == s.length() - 1) {
                for(int j=s.length()-1; j>=0; j--) cout << s[j];
                cout << '\n';
            } else {
                cout << s[i];
                for(int j=0; j<s.length() - 2; j++) cout << ' ';
                cout << s[s.length() - 1 - i] << '\n';
            }
        }
    }
    return 0;
}