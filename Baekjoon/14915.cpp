#include <iostream>
#include <algorithm>
using namespace std;

string translate(int num, int n) {
    if(num == 0) return "0";
    string ret = "";

    while(num > 0) {
        int rest = num % n; 
        if(rest < 10) ret += '0' + rest;
        else ret += 'A' + (rest % 10);
        num /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int n, m;
    cin >> m >> n;
    cout << translate(m, n) << '\n';
    return 0;
}