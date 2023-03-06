#include <iostream>
#include <cstring>
using namespace std;

int sum[101];

int oddSum(int n) {
    if(sum[n] != -1) return sum[n];

    return sum[n] = n + oddSum(n-2);
}

int main() {
    int t;
    cin >> t;

    memset(sum, -1, sizeof(sum));
    while(t--) {
        int n;
        cin >> n;
        cout << oddSum(n) << '\n';
    }
    return 0;
}