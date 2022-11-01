#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string b = "";

    while(n > 0) {
        b += (n % 2) + '0';
        n /= 2;
    }
    reverse(b.begin(), b.end());
    cout << b << '\n';
    return 0;
}