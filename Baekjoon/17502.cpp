#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    int len = str.length();
    for(int i=0; i<=len/2; i++) {
        char& s = str[i];
        char& e = str[len-1-i];
        if(s == '?' && e == '?') s = e = 'a';
        else if(s == '?') s = e;
        else if(e == '?') e = s;
    }
    cout << str << '\n';
    return 0;
}