#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        long long num = 1;
        int cnt = 1;

        while(num % n != 0) {
            cnt++;
            num = (num * 10 + 1) % n;
        }
        cout << cnt << '\n';
    }
    return 0;
}