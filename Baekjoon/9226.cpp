#include <iostream>
#include <set>
using namespace std;

int main() {
    while(true) {
        string s;
        cin >> s;
        if(s == "#") break;

        set<char> c = {'a', 'e', 'i', 'o', 'u'};
        int i;
        bool find = false;
        for(i=0; i<s.length(); i++) {
            if(c.find(s[i]) != c.end()) {
                find = true;
                break;
            }
        }
        if(!find) cout << s << "ay\n";
        else cout << s.substr(i, s.length()-i) << s.substr(0, i) << "ay\n";
    }
    return 0;
}