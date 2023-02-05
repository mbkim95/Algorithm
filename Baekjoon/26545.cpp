#include <iostream>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    for(long long i=0; i<n; i++) {
        long long tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum << '\n';
    return 0;
}