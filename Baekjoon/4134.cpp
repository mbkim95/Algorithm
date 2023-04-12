#include <iostream>
#include <cmath>
using namespace std;

bool check(long long n) {
    if(n <= 1) return false;
    for(int i=2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        while(!check(n)) {
            n++;
        }
        cout << n << '\n';
    }
    return 0;
}