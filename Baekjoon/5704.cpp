#include <iostream>
#include <set>
using namespace std;

int main() {
    string str;

    while(true) {
        getline(cin, str);
        if(str == "*") break;

        set<char> s;
        for(char c : str) 
            if(c != ' ') s.insert(c);

        if(s.size() == 26) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}