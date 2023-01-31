#include <iostream>
#include <algorithm>
using namespace std;

string toString(long long num, int n) {
    string ret = "";
    while(num > 0) {
        ret += (num % n) + '0';
        num /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool isPalindrome(string& n) {
    int len = n.length();
    for(int i=0; i<len/2; i++) {
        if(n[i] != n[len-1-i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, n;
        cin >> a >> n;
        string s = toString(a, n);
        cout << isPalindrome(s) << '\n';
    }
    return 0;
}