#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    while(n > 0) {
        int t = n % 10;
        sum += (t * t * t * t * t);
        n /= 10;
    }
    cout << sum << '\n';
    return 0;
}