#include <iostream>
using namespace std;

int main() {
    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;

        while(n >= 10) {
            int tmp = 0;
            while(n > 0) {
                tmp += (n % 10);
                n /= 10;
            }
            n = tmp;
        }
        cout << n << '\n';
    }
    return 0;
}