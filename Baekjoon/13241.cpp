#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    cout << a * b / gcd(a, b) << '\n';
    return 0;
}