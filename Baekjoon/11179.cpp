#include <iostream>
#include <algorithm>
using namespace std;

string toBinary(int n) {
    string b = "";

    while(n > 0) {
        b += (n % 2) + '0';
        n /= 2;
    }
    reverse(b.begin(), b.end());
    return b;
}

int toReverseInt(string b) {
    int n = 0;
    int t = 1;

    for(char c : b) {
        n += (c - '0') * t;
        t *= 2;
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    string b = toBinary(n);
    cout << toReverseInt(b) << '\n';
    return 0;
}