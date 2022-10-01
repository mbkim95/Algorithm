#include <iostream>
#include <algorithm>
using namespace std;

long long to_long_long(string b) {
    long n = 1, ret = 0;
    for(int i=b.length()-1; i>=0; i--) {
        ret += (b[i] - '0') * n;
        n *= 2;
    }
    return ret;
}

string to_binary(long long n) {
    string ret = "";
    while(n) {
        ret += ('0' + (n % 2));
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string b1, b2;
    cin >> b1;
    cin >> b2;
    cout << to_binary(to_long_long(b1) * to_long_long(b2)) << '\n';
    return 0;
}