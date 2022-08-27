#include <iostream>
using namespace std;

int cnt;

int fib(int n) {
    if (n == 1 || n == 2) {
        cnt++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    fib(n);

    cout << cnt << ' ' << n - 2 << '\n';
    return 0;
}